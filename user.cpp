#include "user.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <iostream>
int user::konnect()
{
    cliLen = sizeof (cliAddr);
    return 0;
}
int user::str_up(char* stptr)
{
    while (*stptr != '\0')
    {
        *stptr = toupper((int) * stptr);
        stptr++;
    }
    return 0;
}


