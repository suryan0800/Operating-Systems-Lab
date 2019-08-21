#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>



sem_t sem_produce,sem_consume;
int sharedmemory;

void *Producer()
{
    int n = 0;
    while(n < 5)
    {
        n++;
        sem_wait(&sem_produce);        
        sharedmemory = rand()/10000000;
        printf("Produced Product : %d \n",sharedmemory);
        sem_post(&sem_consume);
    }
}

void *Consumer()
{
    int n = 0;
    while(n < 5)
    {
        n++;
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
    
    sem_init(&sem_produce,0,1);
    sem_init(&sem_consume,0,0);

    pthread_create(&produce,NULL,Producer,NULL);
    pthread_create(&consume,NULL,Consumer,NULL);
    
    pthread_join(produce,NULL);
    pthread_join(consume,NULL);


}
