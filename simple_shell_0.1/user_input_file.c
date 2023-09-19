#include"mjsh_main.h"

/**
 * instraction_reader - reades the user input command
 * it trims leading whitespace from the input command and handles cases where
 * the input command is empty.
 * the trimmed command is then pased to the 'execution' function for execution
 *
 * @text_command: the command being input
 * the input command read from stdin
*/

void execution(char *trimmed_text, char *envp[]);
void instraction_reader(void)
{
    char text_command[100];
    char *trimmed_text;
    char *envp[1];
    size_t text_length;

    if (fgets(text_command, sizeof(text_command), stdin) == NULL)
    {
        perror("EXIT");
        exit(1);
    }
    text_command[strcspn(text_command, "\n")] = '\0';

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


    execution(trimmed_text, envp);
}
