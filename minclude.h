#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstdio>
#include <unistd.h> /* close */
#include <cstdlib>
#include <iostream>
#include <pthread.h>
#include <new>
#include <vector>
#include <cstring>

#define SUCCESS 0
#define ERROR    1
#define SERVER_PORT 15000
#define MAX_MSG 100
#define MAX_USERS 10
#define MAX_NAME 15


