#include "mjsh_main.h"

/**
 * execution - execute a command specified by 'trimmed_text' with given environment variables
 * This function creates a child process using fork() and handles errors related to process creation
 * and command execution.
 *
 * @trimmed_text: the command to be executed with leading and trailing whitespace trimmed.
 * @envp: the array of environment variables to pass to the executed command.
 * Return: 0 on success, -1 on failure.
 */
int execution(char *trimmed_text) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Child process failed to be created");
        exit(1);
    }

    if (child_pid == 0) {
        char *args[10];
        int arg_count;

        tokenizeInput(trimmed_text, args, &arg_count);

        if (execvp(args[0], args) == -1) {
            perror("Execution failed");
            exit(1);
        }
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            perror("Child process did not exit normally");
            return -1;
        }
    }

    return -1;
}