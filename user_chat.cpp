#include "user_chat.h"
void *user_chat(void *pt)
{
    int *i,j;
    i = (int *)pt;
    j=*i;
    char tempbuffer[MAX_MSG];
// name[MAX_NAME];
    memset(tempbuffer, 0x0, MAX_MSG);
    j--;
    cout << "Thread number " << j << "\n";
    recv(mat[j].ui.NEWSD, tempbuffer, MAX_MSG, 0);
    cout << tempbuffer;
    send(mat[j].ui.NEWSD, "HELLO! ", strlen("HELLO! ") + 1, 0);
    send(mat[j].ui.NEWSD, tempbuffer, strlen(tempbuffer) + 1, 0);
    send(mat[j].ui.NEWSD, " Welcome to my chat\n", strlen(" Welcome to my chat\n") + 1, 0);
	
	 while (1)
    	{
	        send(mat[j].ui.NEWSD, "\nSend your message: ", strlen("\nSend your message: ") + 1, 0);
        	memset(tempbuffer, 0x0, MAX_MSG);
	        if (recv(mat[j].ui.NEWSD, tempbuffer, MAX_MSG, 0) >= 0)
		{
		  cout << tempbuffer << " ";
		  if (strcmp(tempbuffer,"logout_now_")==0) break;
		}
        	else continue;
	}
	    cout << "Logged out\n";
	    close(mat[j].ui.NEWSD);
	    cout << "Thread " << j << " closed\n";
	    pthread_exit(NULL);
}
