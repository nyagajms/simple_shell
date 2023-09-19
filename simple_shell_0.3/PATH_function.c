#include "mjsh_main.h"
/**
 * checkCommandInPath - serach for and execute command in the system's PATH.
 * This function checks whether the given 'trimmed_text' represents an absolute or relative
 * path to an executable file.
 *if not it seraches for the command in the listed directories in the PATH environment variables.
 *if a matching executable is found it is executed as a child process.
 */

void checkCommandInPath(char *trimmed_text, char *envp[])
{
    if (strchr(trimmed_text, '/') == NULL)
    {
        char *path = getenv("PATH");
        char *dir;
        char path_copy[1024];
        int found = 0;
        char *args[10];
        int arg_count;
        if (path == NULL) 
        {
            perror("There is no PATH environment variable set");
            exit(1);
        }

        strcpy(path_copy, path);
        dir = strtok(path_copy, ":");

        while (dir != NULL) 
        {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir, trimmed_text);
            if (access(full_path, X_OK) == 0) 
            {
                pid_t child_pid = fork();

                if (child_pid == -1) 
                {
                    perror("Child process failed to be created");
                    exit(1);
                }

                if (child_pid == 0) 
                {
                    char *exec_args[2];

                    exec_args[0] = trimmed_text;
                    exec_args[1] = NULL;


                    tokenizeInput(trimmed_text, args, &arg_count);
                    
                    if (execve(full_path, exec_args, envp) == -1) 
                    {
                        perror("");
                        exit(1);
                    }
                    exit(0);
                } else 
                {
                    wait(NULL);
                    found = 1;
                    break;
                }
            }
            dir = strtok(NULL, ":");
        }
        if (!found) 
        {
            perror("");
        }
    }
}