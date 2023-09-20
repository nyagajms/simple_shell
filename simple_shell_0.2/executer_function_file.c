#include"mjsh_main.h"
/**
 * execution- execute a command specified to 'trimmed_text' with
 * given environment variables
 * this function creates a child process using fork()
 * it handles eerrors related to the process creation and command execution
 *
 * @trimmed_text: the command to be executed with
 * leading and traling whitespace trimmed.
 * @envp: the array of environment variables to pass to the executed command
 */

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
