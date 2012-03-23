#include "clcon.h"
int clcon::find_server ()
{
  do
    {
      cout << "Give me the server address : ";
      cin >> hostinput;
      h = gethostbyname (hostinput);
      if (h == NULL)
        {
          cerr << "unknown host " << hostinput << "\n";
        }
    }
  while (h == NULL);
  servAddr.sin_family = h->h_addrtype;
  memcpy ((char *) & servAddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
  servAddr.sin_port = htons (SERVER_PORT);
  return 0;
}

int clcon::konnect ()
{

  sockt = socket (AF_INET, SOCK_STREAM, 0);
  if (sockt < 0)
    {
      cerr << "cannot open socket ";
      return 1;
    }
  /* bind any port number */
  localAddr.sin_family = AF_INET;
  localAddr.sin_addr.s_addr = htonl (INADDR_ANY);
  localAddr.sin_port = htons (0);
  if(bind (sockt, (struct sockaddr *) & localAddr, sizeof (localAddr))==0) cout << "\nSocket bound\n"; else{ cerr << "\nCannot bind socket\n"; return 1;}
  if(connect (sockt, (struct sockaddr *) & servAddr, sizeof (servAddr))==0) cout << "\nCONNECTED TO SERVER...\n"; else{ cerr << "\nCannot connect to server\n"; return 1;}
  return 0;
}
int clcon::login ()
{
  cout << "What is your name?\n";
  cin >> message;
  encrypt_send(message);
  return 0;
}



int clcon::encrypt_send(char *ms)
{
  send(sockt, ms, strlen(ms), 0);
  return 0;
}

int clcon::talk()
{
  recv(sockt, message, MAX_MSG, 0);
  cout << message;
  cin >> message;
  encrypt_send(message);
  return 0;
}
int clcon::logout()
{
  strcpy(message,"logout_now_");
//  message="logout_now_";
  encrypt_send(message);
  return 0;  
}


