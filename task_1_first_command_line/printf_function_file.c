#include"mjsh_main.h"

void _printf(const char *text)
{
	write(STDOUT_FILENO, text, strlen(text));
}
