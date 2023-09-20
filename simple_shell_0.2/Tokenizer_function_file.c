#include"mjsh_main.h"
/**
 * tokenizeinput - tokeniz is a string into an array of an argument
 * it takes and trimmed input string 'trimmed_text' and splits it into
 * individual tokens based on spaces ( ' ')
 * it populates an array 'args' with this tokens
 * and updates 'args_count' to indicate
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
