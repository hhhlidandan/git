#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        printf("child ...\n");
         sleep(1);
    }
    else
    {
        printf("father.....\n");
      pid_t ret =wait(NULL);
      if(ret>0)
      {
          printf("wait success...:%d",ret);
      }
    }
}
