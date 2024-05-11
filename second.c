#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <string.h>
#include "systoname.c"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <exe_path>\n", argv[0]);
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
        execlp("wine", "wine", argv[1], NULL);
    } else {
        // Parent process
        int status;

        while (1) {
            waitpid(child_pid, &status, 0);

            if (WIFSTOPPED(status)) {
                struct user_regs_struct regs;
                ptrace(PTRACE_GETREGS, child_pid, NULL, &regs);

                // Print the system call number
                printf("System call: %s\n", (char *)syscall_name(regs.orig_rax));

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
