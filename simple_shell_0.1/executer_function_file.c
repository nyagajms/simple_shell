#include "mjsh_main.h"

/**
 * execution - this is a function for executing a command
 * @trimmed_text: specified by 'trimmed_text'
 * @envp: with the given environment variables
 * it creates a child process using fork()
 * it checks if fork() failed to create a child process
 * code to be executed by the child process
 * prepares arguments for execve() system call
 * the command to be executed
 * null-terminated argument list
 * it executes the specific command with
 * given arguments and environment variables
 * prints an error message if execve() fails
 * exits the child process with an error code
 * code code to be executed by the parent process waits for the child to finish
 */
void execution(char *trimmed_text, char *envp[]) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }

    if (child_pid == 0) {
    
        int pipefd[2];
        if (pipe(pipefd) == -1) {
            perror("pipe");
            exit(1);
        }

        pid_t exec_child_pid = fork();

        if (exec_child_pid == -1) {
            perror("fork");
            exit(1);
        }

        if (exec_child_pid == 0) {
          
            close(pipefd[0]);

           
            dup2(pipefd[1], STDOUT_FILENO);

          
            close(pipefd[1]);

           
            char *args[MAX_INPUT_SIZE];
            int i = 0;
            char *token = strtok(trimmed_text, " ");

            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

           
            if (execve(args[0], args, envp) == -1) {
                perror("execve");
                exit(1);
            }
        } else {
            
            close(pipefd[1]);

     
            char buffer[1024];
            ssize_t bytes_read;

            while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
                write(STDOUT_FILENO, buffer, bytes_read);
            }

          
            close(pipefd[0]);

            
            int status;
            waitpid(exec_child_pid, &status, 0);

            if (status != 0) {
                perror("Child process failed");
                exit(1);
            }
        }

        exit(0);
    } else {
        int status;
        waitpid(child_pid, &status, 0);
    }
}
