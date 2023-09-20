#ifndef MJSH_MAIN_H
#define MJSH_MAIN_H

/**
 * @file mjsh_main.h
 * @brief Header file containing function prototypes and includes.
 */

#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Standard library functions */
#include <string.h>     /* String manipulation functions */
#include <unistd.h>     /* POSIX operating system API */
#include <sys/wait.h>   /* Wait for process termination */
#include <ctype.h>      /* Character handling functions */
#include <stdbool.h>    /* Boolean data type */
#include <stdarg.h>     /* Handling of variable arguments */
#include <sys/types.h>  /* Data types used in system calls */

/* Function prototypes */

/**
 * @brief Custom printf function with variable arguments.
 *
 * This function is used to print formatted text with variable arguments.
 *
 * @param text The format string.
 * @param ...  Additional arguments as needed by the format string.
 */
void _printf(const char *text, ...);

/**
 * @brief Display the shell prompt.
 */
void prompt(void);

/**
 * @brief Read user instructions.
 */
void instruction_reader(void);

/**
 * @brief Execute commands.
 *
 * @param trimmed_text The command to be executed.
 * @param envp         The environment variables.
 */
void execution(char *trimmed_text, char *envp[]);

/**
 * @brief Tokenize commands.
 *
 * @param input     The command to be executed.
 * @param args      Arguments passed.
 * @param arg_count Count of arguments.
 */
void tokenizeInput(char *input, char *args[], int *arg_count);

/**
 * @brief Find the path of the commands.
 *
 * @param trimmed_text The command to be executed.
 * @param envp         The environment variables.
 */
void checkCommandInPath(char *trimmed_text, char *envp[]);

/**
 * @brief Exiting function.
 */
void exitShell(void);

/**
 * @brief Show environment function.
 */
void envShell(void);

#endif
