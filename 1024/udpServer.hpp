#pragma once

#include<iostream>
#include<string>
#include<cstring>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
using namespace std;
class Server{
    private:
        int sock;
        int port;
        string ip;
    public:
        Server(string ip_="127.0.0.1",int port_= 8080):sock(-1),port(port_),ip(ip_)
        {

        }
        void InitServer()
        {
            sock = socket(AF_INET,SOCK_DGRAM,0);
            if(sock<0)
            {
                cerr<<"socket error"<< endl;
                exit(2);
            }
            cout << "init...socket create success:"<< sock << endl;

            struct sockaddr_in local;
            local.sin_family=AF_INET;
            local.sin_port=htons(port);
            local.sin_addr.s_addr=inet_addr(ip.c_str());

            int ret=bind(sock,(sockaddr*)&local,sizeof(local));
            if(ret<0)
            {
                cerr<<"bind error"<< endl;
                exit(3);
            }
            cout<<"init...socket bind success:"<< sock<< endl;

        }
        void Start()
        {
            char buf[1024]= {0
            };
            cout<<"test"<<endl;
            for( ; ;)
            {
                struct sockaddr_in peer;
                socklen_t len =sizeof(peer);
  
                ssize_t s= recvfrom(sock,buf,sizeof(buf)-1,0,(struct sockaddr*)&peer,&len);
  
                cout<<peer.sin_port<<endl;
                cout<<s<<endl;
                cout<<buf<<endl;
                if(s>0)
                {
                    buf[s]=0;
                    cout << "client#" << buf << endl;
                    sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&peer,len);
                }
            }
        }
        ~Server()
        {
        }
};
