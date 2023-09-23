#include"mjsh_main.h"

/**
 * instraction_reader - reades and process the user input command
 * it trims leading and traling white spaces and handles cases of empty
 * command in input.
 * the trimmed command is prepared for execution
 *
 * @text_command: the command being input
*/ 

void execution(char *trimmed_text, char *envp[]);
void checkCommandInPath(char *command_line);
void instraction_reader(void)
{
    char text_command[100];
    char *trimmed_text;
    char *envp[] = { NULL };
    size_t text_length;

    if (fgets(text_command, sizeof(text_command), stdin) == NULL)
    {
        if (isatty(STDIN_FILENO))
        {
            perror("EXIT");
        }
        exit(1);
    }
    text_command[strcspn(text_command, "\n")] = '\0';
    
    if (strcmp(text_command, "exit") == 0)
    {
        exitShell();
    }
    if (strcmp(text_command, "env") == 0) 
    {
        envShell();
    }

    trimmed_text = text_command;

    while (isspace(*trimmed_text))
    {
        trimmed_text++;
    }

    text_length = strlen(trimmed_text);

    while (text_length > 0 && isspace(trimmed_text[text_length - 1]))
    {
        trimmed_text[--text_length] = '\0';
    }

    if (trimmed_text[0] == '\0')
    {
        return;
    
    }
    if (trimmed_text[0] == '/') 
    {
        execution(trimmed_text, envp);
    }
    else
    {
        checkCommandInPath(trimmed_text);
    }

}
