/* 
 * File:   main.cpp
 * Author: master
 *
 * Created on April 2, 2010, 6:26 PM
 */
#include "user_chat.h"
#include "startup_server.h"
using namespace std;

us mat[MAX_USERS];
int main(int argc, char** argv)
{
    int i = 0;
    startup_server serv;
    serv.setupsock();
    for (i = 0;i<MAX_USERS; i++)
    {

    while (1)    {
        if ((mat[i].ui.NEWSD = (accept(serv.sd, (struct sockaddr *) &mat[i].ui.cliAddr, (socklen_t *) &mat[i].ui.cliLen))) > 0)
        {
            pthread_create(&mat[i].thread,NULL,&user_chat, &i);
	    i++;
            cout << "Thread " << i << " started\n";
        }
    }
    }
    return 0;
}










