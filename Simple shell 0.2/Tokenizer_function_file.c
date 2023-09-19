#include"mjsh_main.h"
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