#include "mjsh_main.h"


/**
 * envShell - environment printing
 */

void envShell(void)
{
    extern char **environ;
    char **env = environ;
    int i; 

    for (i = 0; env[i] != NULL; i++) 
    {
        _printf("%s\n", env[i]);
    }
}
