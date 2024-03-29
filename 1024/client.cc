#include "udpClient.hpp"
#include<iostream>
using namespace std;
void Usage(string proc)
{
    cout << proc << "sever_ip server_port" << endl;
}
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    Client *ct = new Client(argv[1],atoi(argv[2]));

    ct-> InitClient();
    ct-> Run();
    delete ct;
    return 0;
}
