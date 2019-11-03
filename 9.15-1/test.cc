#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<pthread.h>

using namespace std;

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
void *Signal(void *signal)
{
    while(1)
    {
        pthread_cond_signal(&cond);
        sleep(3);
    }
}
int main()
{
    pthread_t t1,t2;

    pthread_mutex_init(&lock,NULL);
    pthread_cond_init(&cond,NULL);

    pthread_create(&t1,NULL,Wait,NULL);
    pthread_create(&t2,NULL,Signal,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
}
