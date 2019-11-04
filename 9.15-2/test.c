#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

pthread_mutex_t lock;
pthread_cond_t cond;

void *Wait(void *arg)
{
    while(1)
    {
        pthread_cond_wait(&cond,&lock);
        printf("active...\n");
    }

}
void *Signal(void *arg)
{
    while(1)
    {
        pthread_cond_signal(&cond);
        sleep(3);
    }
}
int main()
{
    pthread_t tid1,tid2;

    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&lock,NULL);

    pthread_create(&tid1,NULL,Wait,NULL);
    pthread_create(&tid2,NULL,Signal,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&lock);
}
