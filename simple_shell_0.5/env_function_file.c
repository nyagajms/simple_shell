#include"mjsh_main.h"

/**
 * envShell - environment printing
*/

void envShell(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_printf("%s\n", *env);
		env++;
	}
}
