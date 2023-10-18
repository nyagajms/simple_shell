#include"mjsh_main.h"

/**
 * _printf - function call for standard output
 * the function formats and prints text to
 *the standard output wit support from various
 * specifiers, similar to the standard C liblary's printf function
 *
 * @text: the text to be printed
 * the format string specifying the text to be printed which may contain format
 * specifers like %d, %s etc.
 *
 * Return: the number of characters written on sucess,
 * occurs during printing
*/

int _printf(const char *text, ...)
{
	int result;

	va_list args;

	va_start(args, text);

	result = vprintf(text, args);
	va_end(args);
	return (result);
}
