#include"mjsh_main.h"

/**
 * instraction_reader - reades the user input command
 * @text_command: the command being input
*/

void execution(char *trimmed_text, char *envp[]);
void checkCommandInPath(char *trimmed_text, char *envp[]);
void instraction_reader(void)
{
    char text_command[100];
    char *trimmed_text;
    char *envp[] = { NULL };
    size_t text_length;

    if (fgets(text_command, sizeof(text_command), stdin) == NULL)
    {
        perror("EXIT");
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
    if (strchr(trimmed_text, '/') != NULL)
    {
        execution(trimmed_text, envp);
    }
    else
    {
        checkCommandInPath(trimmed_text, envp);
    }

}
