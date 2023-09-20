#include"mjsh_main.h"

/**
 * execution - this is a function for executing a command
 * @trimmed_text: specified by 'triimmed_text'
 * @envp: with the given enviromnent variables
 * it creats a child process using fork()
 * it checks if fork() failed to create a child process
 * code to be executed by the child process
 * prepares argument for execve() system call
 * the command to be executed
 * null-terminated argument list
 * it executes the specific command with
 * given arguments and environment variables
 * prints an error message if execve() fails
 * exits the child process with an error code
 * code code to be executed by the parent process waits for the child to finish
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
