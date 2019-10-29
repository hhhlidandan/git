#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    pid_t id=fork();
    if(id==0)
    {
        printf("child...\n");
        sleep(8);
        exit(30);
    }
    else
    {
        printf("father...\n");
        sleep(15);
        int status=0;
        pid_t ret= waitpid(id,&status,0);
        if(ret>0)
        {
           printf("wait success..: %d\n",ret);
           printf("signal:%d\n",status&0x7F);
           printf("code:%d\n",(status>>8)&0xFF);
        }
        sleep(5);
    }
}
