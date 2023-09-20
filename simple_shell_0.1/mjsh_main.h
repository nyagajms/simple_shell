#ifndef MJSH_MAIN_H
#define MJSH_MAIN_H

/* Header file containing function prototypes and includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>
#include <sys/types.h>

/* Function prototypes */

/**
 * _printf - Custom printf function with variable arguments.
 *
 * @text: The format string.
 * @...: Additional arguments as needed by the format string.
 */
void _printf(const char *text, ...);

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

#endif
