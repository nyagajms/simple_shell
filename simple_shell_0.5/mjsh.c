#include"mjsh_main.h"

/**
 * main - main shell file
 * Return: 0
*/

int main(void)
{
	for (;;)
	{
		prompt();
		instruction_reader();

	}

	return (0);
}
