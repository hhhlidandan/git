#pragma once

#include<iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
using namespace std;

class Client{
    private:
        int sock;
        string peer_ip;
        int peer_port;
    public:
        Client(string _ip,int _port):peer_ip(_ip),peer_port(_port)
        {
            sock=-1;
        }
        void InitClient()
        {
            sock = socket(AF_INET,SOCK_DGRAM,0);
            if(sock<0)
            {
                cerr <<" socket error "<< endl;
            }
        }
        void Run()
        {
            bool quit=false;
            char buf[1024];
            string message;
            while(!quit)
            {
                struct sockaddr_in peer;
                peer.sin_family = AF_INET;
                peer.sin_addr.s_addr = inet_addr(peer_ip.c_str());
                peer.sin_port = htons(peer_port);

                socklen_t len = sizeof(peer);
                cout << "Please Enter#";
                cin >> message;
                cout<<message<<endl;
                //cout<<sendto(sock,message.c_str(),message.size(),0,(struct sockaddr*)&peer,sizeof(peer))<<endl;
                sendto(sock,message.c_str(),message.size(),0,(struct sockaddr*)&peer,sizeof(peer));
                ssize_t s = recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&peer,&len);
                if(s>0)
                {
                    buf[s]=0;
                    cout << " server echo# " << buf << endl;
                }
            }
        }
        ~Client()
        {
            if(sock > 0)
                 close(sock);
        }
};


