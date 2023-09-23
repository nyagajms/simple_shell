#include "mjsh_main.h"
#include <stdio.h>

int main(void)
{
    int is_interactive = isatty(fileno(stdin));

    for (;;)
    {
 

        instraction_reader();

        if (!is_interactive)
        {
            break; 
        }
    }

    return (0);
}
