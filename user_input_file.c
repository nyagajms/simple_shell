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
    char input[1024]; 
    char *envp[] = { NULL };
    char *command_start;
    char *command_end;
    char *trimmed_text;
    size_t text_length;

    while (1) {
        printf("$ ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            if (isatty(STDIN_FILENO)) {
                perror("EXIT");
            }
            exit(0);
        }

        command_start = input;

        while (1) {
           
            command_end = strchr(command_start, '\n');
            if (command_end == NULL) {
                break; 
            }

            *command_end = '\0';

            trimmed_text = command_start;

            while (isspace(*trimmed_text)) {
                trimmed_text++;
            }

            text_length = strlen(trimmed_text);

            while (text_length > 0 && isspace(trimmed_text[text_length - 1])) {
                trimmed_text[--text_length] = '\0';
            }

            if (*trimmed_text != '\0') {
                if (strcmp(trimmed_text, "exit") == 0) {
                    exit(0);
                } else if (strcmp(trimmed_text, "env") == 0) {
                    envShell();
                    exitShell(0);
                } else {
                    if (trimmed_text[0] == '/') {
                        int exit_status = execution(trimmed_text, envp);
                        exitShell(exit_status);
                    } else {
                        checkCommandInPath(trimmed_text, envp);
                    }
                }
            }

            command_start = command_end + 1; 
        }
    }
}
