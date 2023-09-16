#ifndef MJSH_MAIN_H
#define MJSH_MAIN_H


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include<stdbool.h>
#include <stdarg.h>
#include <sys/types.h>

/**
 * mjsh_main - header files and prototypes
 * @text: The text to be printed
*/

int _printf(const char *text, ...);
void prompt(void);
void instraction_reader(void);
void execution(char *trimmed_text, char *envp[]);

#endif
