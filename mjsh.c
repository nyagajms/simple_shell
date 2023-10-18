#include"mjsh_main.h"
/**
 * main - main shell file
 * this is the main entry point that sets up infinite loop to continously
 * prompt the user for commands and process those commands.
 * it runs till the user exits.
 *
 * Return: Always 0 to indicate sucess
*/

int main(void)
{
	int is_interactive = isatty(fileno(stdin));

	for (;;)
	{
		if (is_interactive)
			prompt();
		instraction_reader();
	}

	return (0);
}
