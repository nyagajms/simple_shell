#include "mjsh_main.h"

/**
 * exitShell - for exiting the shell on call with a specific status code
 * @status_code: the exit status code
 */
void exitShell(int status_code)
{
    exit(status_code);
}
