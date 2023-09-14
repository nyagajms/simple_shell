#include"mjsh_main.h"

/**
 * instraction_reader - reades the user input command
 * @text: the command being input
 * @length: the length of the input
*/

void instraction_reader(void)
{
    char *trimmed_text = text;
    while (isspace(*trimmed_command)) 
    {
        trimmed_command++;
    }
    size_t text_lengh = strlen(trimmed_command);
    
    while (text_length > 0 && isspace(trimmed_command[text_length - 1])) 
    {
        trimmed_command[--text_length] = '\0';
    }
    if (strlen(trimmed_command) == 0) 
    {
        continue;
    }
}
