#include"mjsh_main.h"

/**
 * execution - file that enables the command to be executed
 * @text: text command inputed by the user
*/
void execution(const char *text)
{
	__pid_t second_pid = fork();

	if (second_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (second_pid == 0)
	{
		execlp(text, text, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

}
