#include <pthread.h>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include "user.h"

#define SUCCESS 0
#define ERROR    1
#define SERVER_PORT 15000
#define MAX_MSG 100
#define MAX_USERS 10
#define MAX_NAME 15

using namespace std;

void *user_chat(void *pt);
struct us
{
    user ui;
    int flag;
    pthread_t thread;
};

extern us mat[MAX_USERS];
