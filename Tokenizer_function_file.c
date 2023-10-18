#include"mjsh_main.h"
/**
 * tokenizInput - tokeniz a string into an array of arguments
 * takes 'trimmed_text' and splits it into tokens based on space (' ')
 * it populates an array 'args' with these tokens and updates 'args_count' to indicate
 * the number of tokens
 */
void tokenizeInput(char *trimmed_text, char *args[], int *arg_count) 
{
     
    char *token;
    
    *arg_count = 0;

    token = strtok(trimmed_text, " "); 
    
    while (token != NULL) 
    {
        args[(*arg_count)++] = token;
        token = strtok(NULL, " ");
    }
    args[*arg_count] = NULL;

}
 