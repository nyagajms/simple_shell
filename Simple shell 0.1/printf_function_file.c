#include"mjsh_main.h"

/**
 * _printf - function call for standard output
 * @text: the text to be printed
*/
void _printf(const char *text)
{
	write(1, text, strlen(text));
}
