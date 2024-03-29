#include "udpServer.hpp"
using namespace std;

void Usage(string proc)
{
    cout << proc << " IP " << "PORT"<<endl;
}
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(1);
    }
    Server *sp= new Server(argv[1],atoi(argv[2]));
   sp->InitServer();
    sp->Start();
    delete sp;
}
