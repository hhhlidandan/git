
#include<unistd.h>
#include<pthread.h>
#include<iosteram>
#include<queue>

using namespace std;
class BlockQueue
{
    private:
        queue<int> q;
        int cap;
        pthread_mutex_t lock;
        pthread_cond_t c_cond;
        pthread_cond_t p_cond;
    private:
        LockQueue()
        {
            pthread_mutex_lock(&lock);
        }
        UnlockQueue()
        {
            pthread_mutex_unlock(&lock);
        }
        bool BlockQueueIsFull()
        {
            return q.size()==cap;
        }
        bool BlockQueueIsEmpty()
        {
            return q.size()==0;
        }
        void ProductWait()
        {
            pthread_cond_wait(&p_cond,&mutex);
        }
        void ConsumerWait();
        {
            pthread_cond_wait(&c_cond,&mutex);
        }
        void SignalConsumer()
        {
            pthread_cond_signal(&c_cond);
        }
        void SignalProducter()
        {
            pthread_cond_signal(&p_cond);
        }

    public:
        BlockQueue(int cap = 32):cap(cap_)
        {
            pthread_mutex_init(&lock,nullptr);
            pthread_cond_init(c_cond,nullptr);
            pthread_cond_init(p_cond,nullptr);
        }
        //producter
        void PushData(int data)
        {
            LockQueue();
            while(1)
            {
                if(BlockQueueIsFull())
                {
                 SignalConsumer();
                 ProductWait();
                }
                q.push(data);
            }
            UnlockQueue();
        }
        //consumer
        void PopData(int out)
        {
            LockQueue();
            while(1)
            {
                if(BlockQueueIsEmpty())
                {
                    SignalProducter();
                    ConsumerWait();
                }
                out=q.front();
                q.pop(data);
            }
            UnlockQueue();
        }
         ~BlockQueue()
        {
             pthread_mutex_destroy(&lock,nullptr);
             pthread_cond_destroy(&c_cond,nullptr);
             pthread_cond_destroy(&p_cond,nullptr);
         }
};
int main()
{
    BlockQueue *
    pthread_create()
}
