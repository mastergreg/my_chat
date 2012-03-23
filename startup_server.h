#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h> /* close */
#include <iostream>

#define SUCCESS 0
#define ERROR    1
#define SERVER_PORT 15000
#define MAX_MSG 100
#define MAX_USERS 10
#define MAX_NAME 15



using namespace std;


class startup_server
{
    struct sockaddr_in servAddr;
public:
    int sd;
    int setupsock();
};
