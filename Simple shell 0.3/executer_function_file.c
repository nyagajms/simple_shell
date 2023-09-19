#include"mjsh_main.h"

void execution(char *trimmed_text, char *envp[])
{

    pid_t child_pid = fork();

    if (child_pid == -1)
    {
        perror("child process failed to be created");
        exit(1);
    }

    if (child_pid == 0)
    {
        char *args[10];
        int arg_count;

        tokenizeInput(trimmed_text, args, &arg_count);

        if (execve(args[0], args, envp) != 0) 
        {
            perror("");
            exit(1);
        }
    }    
    else
    wait(NULL);
}
 