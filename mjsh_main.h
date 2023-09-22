#ifndef MJSH_MAIN_H
#define MJSH_MAIN_H

/**
 * mjsh_main - Header file containing function prototypes and includes
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include<stdbool.h>
#include <stdarg.h>
#include <sys/types.h>

/* Function prototypes */
void betty(void);

/**
 * _printf - Custom printf function with variable arguments.
 *
 * @text: The format string.
 * @...: Additional arguments as needed by the format string.
*/
int _printf(const char *text, ...);

/**
 * prompt - Display the shell prompt.
*/
void prompt(void);

/**
 * instruction_reader - Read user instructions.
*/
void instruction_reader(void);

/**
 * execution - Execute commands.
 *
 * @trimmed_text: The command to be executed.
 * @envp: The environment variables.
*/
void execution(char *trimmed_text, char *envp[]);

/**
 * tokenizeInput - tokenize commands.
 *
 * @input: The command to be executed.
 * @args: arguments passed
 * @arg_count: counts no of arguments
*/
void tokenizeInput(char *input, char *args[], int *arg_count);

/**
 * checkCommandInPath - looks for the path of the commands.
 *
 * @trimmed_text: The command to be executed.
 * @envp: The environment variables.
*/
void checkCommandInPath(char *trimmed_text, char *envp[]);

/**
 * exitShell - exiting function
*/
void exitShell(void);

/**
 * envShell - show environment  function
*/
void envShell(void);

#endif
