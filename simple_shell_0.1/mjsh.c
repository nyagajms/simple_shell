#include"mjsh_main.h"
/**
 * main - Entry point for the main shell program
 *
 * This function serves as the main entry point for the shell program
 * it runs an infinite loop that repeatedly prompts for user
 * input and reads a progress instructions
 *
 * Return: Always 0 for sucess
*/

int main(void)
{
for (;;)
{
prompt();
instruction_reader();
}

return (0);
}
