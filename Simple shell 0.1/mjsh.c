#include"mjsh_main.h"
/**
 * main - main shell file
 * Return: 0
*/

int main (void)
{
    for (;;)
    {
        void prompt(void);
        if (fgets(text, sizeof(text), stdin) == NULL)
        {
            _printf("EXIT\n");
            break;
        }
        text[strcspn(text, "\n")] = '\0';
        
        void instraction_reader(char *text, size_t length);
        void execution(const char *text);
    }

    return (0);
}
