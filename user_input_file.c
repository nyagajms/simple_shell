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
void instraction_reader(void) 
{
    char *envp[] = { NULL };
    char *line = NULL;
    size_t len = 0;
    ssize_t n; 

    while (1) {
        printf("mjsh$ ");  
        n = getline(&line, &len, stdin); 
        if (n == -1) {
            if (isatty(STDIN_FILENO)) {
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
                printf("Exit status: %d\n", exit_status);
            } else {
                checkCommandInPath(trimmed_text, envp);
            }
        }
    }
    free(line);
}
