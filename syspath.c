#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <fcntl.h>
#include <string.h>
#include "systoname.c"

#define MAX_PATH_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <program>\n", argv[0]);
        return 1;
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    }

    if (child_pid == 0) {
        // Child process
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        execl(argv[1], argv[1], NULL);
    } else {
        // Parent process
        int status;

        while (1) {
            waitpid(child_pid, &status, 0);

            if (WIFSTOPPED(status)) {
                struct user_regs_struct regs;
                ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);

                // Check if the system call is related to file operations
                if (regs.orig_rax == SYS_open || regs.orig_rax == SYS_openat) {
                    char path[MAX_PATH_LEN];
                    long arg = ptrace(PTRACE_PEEKDATA, child_pid, regs.rdi, NULL); // Assuming the path is in the rdi register

                    int i = 0;
                    while (arg != 0 && i < MAX_PATH_LEN - 1) {
                        path[i] = (char)(arg & 0xFF);
                        arg >>= 8;
                        i++;
                    }
                    path[i] = '\0';

                    // Print the system call and the corresponding file path
                    printf("System call: %s\nFile path: %s\n", (char *)syscall_name(regs.orig_rax), path);
                } else {
                    // Print the system call without the file path
                    printf("System call: %s\n", (char *)syscall_name(regs.orig_rax));
                }

                ptrace(PTRACE_SYSCALL, child_pid, NULL, NULL);
            } else if (WIFEXITED(status)) {
                // Child process has exited
                break;
            } else {
                // Some other status (should handle error conditions)
                perror("waitpid");
                break;
            }
        }
    }

    return 0;
}
