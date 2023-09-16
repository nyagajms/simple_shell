#include "mjsh_main.h"

void execution(char *trimmed_text, char *envp[])
{
    pid_t child_pid;
    char *args[2];
    char full_path[256];
    int status;

    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0)
    {
        args[0] = trimmed_text;
        args[1] = NULL;


        snprintf(full_path, sizeof(full_path), "/bin/%s", trimmed_text);

        if (access(full_path, X_OK) == -1)
        {
            perror("Access error");
            exit(1);
        }

        printf("Executing: %s\n", full_path);

        if (execve(full_path, args, envp) == -1)
        {
            perror("Execve failed");
            exit(1);
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status))
        {
            printf("Command exited with status %d\n", WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Command terminated by signal %d\n", WTERMSIG(status));
        }
        else
        {
            printf("Command ended abnormally\n");
        }
    }
}
