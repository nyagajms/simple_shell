#include"mjsh_main.h"

/**
 * _printf - function call for standard output
 * @text: the text to be printed
*/

int _printf(const char *text, ...) 
{
	int result;
    va_list args;
    va_start(args, text);
    result = vprintf(text, args);
    va_end(args);
    return result;
}
