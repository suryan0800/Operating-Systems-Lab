#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<assert.h>
#include<errno.h>
#include<time.h>


sem_t sem_produce,sem_consume;
int sharedmemory;

void *Producer()
{
    while(1)
    {
        
        sem_wait(&sem_produce);        
        sharedmemory = rand();
        printf("Produced Product : %d \n",sharedmemory);
        sem_post(&sem_consume);
    }
}

void *Consumer()
{
    while(1)
    {
        
        sem_wait(&sem_consume);
        sleep(1);              
        printf("Consumed Product : %d \n",sharedmemory );
        sharedmemory = 0;
        sem_post(&sem_produce);
    }
}

void main()
{
    pthread_t produce,consume;
    int a = 0,b = 1;
    sem_init(&sem_produce,0,1);
    sem_init(&sem_consume,0,1);

    pthread_create(&produce,NULL,Producer,(void *)a);
    pthread_create(&consume,NULL,Consumer,(void *)b);
    
    pthread_join(produce,NULL);
    pthread_join(consume,NULL);


}
