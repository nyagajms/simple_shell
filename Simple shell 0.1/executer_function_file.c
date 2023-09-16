#include"mjsh_main.h"

void execution(char *trimmed_text, char *envp[])
{
    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("Fork failed");
        exit(1);
    }

    if (child_pid == 0)
    {
        char *args[2];
        args[0] = trimmed_text;
        args[1] = NULL;

        if (execve(trimmed_text, args, envp) == -1)
        {
            perror("Execve failed");
            exit(1);
        }
    }
    else
    {
        int status;
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
