#ifndef MJSH_MAIN_H
#define MJSH_MAIN_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdbool.h>

/**
 * mjsh_main - header files and prototypes
 * @text: The text to be printed
*/

void _printf(const char *text);
void prompt(void);
void instraction_reader(char *text, size_t length);
void execution(const char *text);

#endif
