#include"mjsh_main.h"

/**
 * _printf - function call for standard output
 * this function provides a simplified version of the printf function
 * for printing formatted text to the standard output.
 * it takes aformat string 'text' and any additional arguments specified by the format
 * string allowing for argument list variables.
 *
 * @text: the format string specifying the text to be printed
 * it may contain format specifiers like %d, %s etc.
 * it should match the the types of additonal arguments
*/

void _printf(const char *text, ...) 
{
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);
}
