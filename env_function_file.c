#include"mjsh_main.h"

/**
 * envShell - environment printing
*/

void envShell(void)
{
	extern char **environ;
	char **env = environ;

	while (*env != NULL)
	{
		_printf("%s\n", *env);
		env++;
	}
}
