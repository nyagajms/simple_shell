#include"mjsh_main.h"

/**
 * _printf - function call for standard output
 * @text: the text to be printed
*/

void _printf(const char *text, ...) 
{
    va_list args;
    va_start(args, text);
    vprintf(text, args);
    va_end(args);
}
