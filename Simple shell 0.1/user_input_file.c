#include"mjsh_main.h"

/**
 * instraction_reader - reades the user input command
 * @text: the command being input
 * @length: the length of the input
*/

void instraction_reader(char *text, size_t length)
{
    size_t text_length;

    if (fgets(text, length, stdin) == NULL)
    {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }

    text_length = strlen(text);

    if (text_length > 0 && text[text_length - 1] == '\n')
    {
        text[text_length - 1] = '\0';
    }
}
