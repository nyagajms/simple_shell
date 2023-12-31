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
#include <sys/stat.h>
#include <errno.h>

/**
 * mjsh_main - header files and prototypes
*/

void betty(void);
char *findCommandInPath(char *command_name);
int _printf(const char *text, ...);
void prompt(void);
void instraction_reader(void);
int execution(char *trimmed_text, char *envp[]);
void tokenizeInput(char *input, char *args[], int *arg_count);

void checkCommandInPath(char *trimmed_text, char *envp[]);
void exitShell(int status_code);
void envShell(void);

#endif
