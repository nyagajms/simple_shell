#include "mjsh_main.h"


/**
 * checkCommandInPath - search for and execute a command in the system's PATH.
 * This function checks whether the given 'command_line' represents an absolute or relative
 * path to an executable file.
 * If not, it searches for the command in the listed directories in the PATH environment variables.
 * If a matching executable is found, it is executed as a child process.
 */

void checkCommandInPath(char *trimmed_text, char *envp[]) {
    pid_t child_pid;

    char *args[10];
    int arg_count;

    tokenizeInput(trimmed_text, args, &arg_count);

    if (args[0] != NULL) {
        int has_directory_path = 0;
        int i;
        for (i = 1; i < arg_count; i++) {
            if (args[i][0] == '/') {
                has_directory_path = 1;
                break;
            }
        }

        if (has_directory_path) {
            char *directory_path = args[0]; 
            struct stat st;
            if (stat(directory_path, &st) == 0 && S_ISDIR(st.st_mode)) {
                args[arg_count] = NULL;
                chdir(directory_path);
            } else {
                fprintf(stderr, "Error: Not a directory: %s\n", directory_path);
                return;
            }
        }

        child_pid = fork();

        if (child_pid == -1) {
            perror("Child process failed to be created");
            exit(1);
        }

        if (child_pid == 0) {
            if (execve(args[0], args, envp) == -1) {
                perror("execve");
                exit(1);
            }
            exit(0);
        } else {
            wait(NULL);
        }
    } else {
        perror("Command not found");
    }
}
