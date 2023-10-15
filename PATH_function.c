#include "mjsh_main.h"

/**
 * checkCommandInPath - search for and execute a command in the system's PATH.
 * This function checks whether the given 'command_line' represents an absolute or relative
 * path to an executable file.
 * If not, it searches for the command in the listed directories in the PATH environment variables.
 * If a matching executable is found, it is executed as a child process.
 */

void checkCommandInPath(char *trimmed_text) {
    char *command_path = findCommandInPath(trimmed_text);

    if (command_path != NULL) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Child process failed to be created");
            exit(1);
        }

        if (child_pid == 0) {
            char *args[10];
            int arg_count;

            tokenizeInput(trimmed_text, args, &arg_count);

            if (execv(command_path, args) == -1) {
                perror("Execution failed");
                exit(1);
            }
        } else {
            int status;
            wait(&status);
            if (WIFEXITED(status)) {
               
            } else {
                perror("Child process did not exit normally");
            }
        }
    } else {
        fprintf(stderr, "Command not found: %s\n", trimmed_text);
    }
}

char *findCommandInPath(char *command_name) {
    char *path = getenv("PATH");
    char *dir;
    char path_copy[1024];
    static char full_path[1024];

    if (path == NULL) {
        return NULL;
    }

    strcpy(path_copy, path);
    dir = strtok(path_copy, ":");

    while (dir != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command_name);
        if (access(full_path, X_OK) == 0) {
            return full_path;
        }
        dir = strtok(NULL, ":");
    }

    return NULL;
}
