#include"mjsh_main.h"

void envShell() 
{
    extern char** environ;

    char **env = environ;

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}
