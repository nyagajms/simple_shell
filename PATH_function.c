#include "mjsh_main.h"

/**
 * checkCommandInPath - search for and execute a command in the system's PATH.
 * This function checks whether the given 'command_line' represents an absolute or relative
 * path to an executable file.
 * If not, it searches for the command in the listed directories in the PATH environment variables.
 * If a matching executable is found, it is executed as a child process.
 */

void checkCommandInPath(char *trimmed_text) {
    pid_t child_pid;

    char *args[10];
    int arg_count;

    tokenizeInput(trimmed_text, args, &arg_count);

    if (args[0] != NULL) {
        child_pid = fork();

        if (child_pid == -1) {
            perror("Child process failed to be created");
            exit(1);
        }

        if (child_pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
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
