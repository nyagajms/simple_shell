#include"mjsh_main.h"

/**
 * _printf - function call for standard output
 * @text: the text to be printed
*/

int _printf(const char *text, ...) 
{
write(STDOUT_FILENO,text,strlen(text));
}
