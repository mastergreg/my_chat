#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h> /* close */
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <cstring>

#define SUCCESS 0
#define ERROR    1
#define SERVER_PORT 15000
#define MAX_MSG 100
#define MAX_USERS 10
#define MAX_NAME 15


using namespace std;

class clcon
{
private:
  struct sockaddr_in localAddr, servAddr;
  struct hostent *h;
  char message[MAX_MSG],hostinput[25];
  int encrypt_send(char *ms);
public:
  int logout();
  int sockt;
  int find_server();
  int konnect();
  int login();
  int talk();
};


