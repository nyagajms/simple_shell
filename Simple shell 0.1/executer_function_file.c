#include"mjsh_main.h"

void execution(const char *text)
{
    pid_t second_pid = fork();

    if (second_pid == -1)
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    else if (second_pid == 0)
    {
        if (execlp(text, text, (char *)NULL) == -1)
        {
            perror("Error in execlp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        int status;
        if (wait(&status) == -1)
        {
            perror("Error in wait");
            exit(EXIT_FAILURE);
        }
        
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status == 0)
            {
                printf("Command '%s' executed successfully\n", text);
            }
            else
            {
            }
        }
    }
}