#include "startup_server.h"

int startup_server::setupsock()
{
    /* create socket */
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0)
    {
        cout << "cannot open socket\n";
        return ERROR;
    }
    /* bind server port */
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servAddr.sin_port = htons(SERVER_PORT);
    if (bind(sd, (struct sockaddr *) & servAddr, sizeof (servAddr)) < 0)
    {
        cout << "CANNOT BIND PORT !!!!!\n";
        return 1;
    }
    cout << "Socket Open. Port Bound.\n";
    if (listen(sd, 5) == 0) cout << "listening...\n";
    return 0;
}


