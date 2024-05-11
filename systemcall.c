#include <stdio.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/user.h>
#include <stdlib.h>
#include <string.h>
#include "systoname.c"

char* get_syscall_path(pid_t pid, long syscall_number) {
    char path[256];
    sprintf(path, "/proc/%d/fd/%ld", pid, syscall_number);
    char buffer[256];
    ssize_t len = readlink(path, buffer, sizeof(buffer) - 1);
    if (len != -1) {
        buffer[len] = '\0';
        return strdup(buffer);
    } else {
        return NULL;
    }
}

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

                // Print the system call number
                printf("System call: %s", (char *)syscall_name(regs.orig_rax));

                // Print the path associated with the system call
                char *path = get_syscall_path(child_pid, regs.orig_rax);
                if (path != NULL) {
                    printf(", Path: %s\n", path);
                    free(path);
                } else {
                    printf("\n");
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
