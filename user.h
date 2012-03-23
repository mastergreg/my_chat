class user
{
public:
    int send_list();
    struct sockaddr_in cliAddr;
    int cliLen, i;
    int NEWSD;
    int current_socket;
    std::string name;
    
    int str_up(char *stptr);
    int konnect();
};

