#include"mjsh_main.h"

/**
 * instraction_reader - reades and process the user input command
 * it trims leading and traling white spaces and handles cases of empty
 * command in input.
 * the trimmed command is prepared for execution
 *
 * @text_command: the command being input
*/ 

int execution(char *trimmed_text, char *envp[]);
void checkCommandInPath(char *trimmed_text, char *envp[]);
void exitShell(int status_code);
void exitShell(int status_code);
#include"mjsh_main.h"

/**
 * instraction_reader - reades and process the user input command
 * it trims leading and traling white spaces and handles cases of empty
 * command in input.
 * the trimmed command is prepared for execution
 *
 * @text_command: the command being input
*/ 

int execution(char *trimmed_text, char *envp[]);
void checkCommandInPath(char *trimmed_text, char *envp[]);
void exitShell(int status_code);
void exitShell(int status_code);
void instraction_reader(void) {
    char *envp[] = { NULL };
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    int is_interactive = isatty(STDIN_FILENO);
    int is_piped = !is_interactive;

    while (1) {
        if (is_interactive) {
            prompt();
        }

        n = getline(&line, &len, stdin);

        if (n == -1) {
            if (is_interactive) {
                perror("EXIT");
            }
            exit(0);
        }

        line[strcspn(line, "\n")] = '\0';

        if (strcmp(line, "exit") == 0) {
            free(line);
            exit(0);
        }
        if (strcmp(line, "env") == 0) {
            envShell();
        } else {
            char *trimmed_text = line;
            if (trimmed_text[0] == '/') {
                int exit_status = execution(trimmed_text, envp);
                if (is_interactive) {
                    printf("Exit status: %d\n", exit_status);
                }
            } else {
                checkCommandInPath(trimmed_text, envp);
            }
        }

        if (!is_piped) {
            break;
        }
    }

    free(line);
}
