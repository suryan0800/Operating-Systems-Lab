#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>


int queue[100];
int front = -1, rear = -1;

void *Producer()
{
    while(1)
    {
        
        if(rear < 10)
        {     
            rear++;
            queue[rear] = rand()/10000000;
            sleep(0.5);
        }
        else{ break; }
    }
}

void *Consumer()
{
    while(1)
    {
        if(front == 9)
        {
            break;
        }
        if(front < rear)
        {
            sleep(1);
            front++;         
            printf("Processed : %d \n",queue[front] );        
        }
        
    }
}

void main()
{
    pthread_t produce,consume;
    
   

    pthread_create(&produce,NULL,Producer,NULL);
    pthread_create(&consume,NULL,Consumer,NULL);
    
    pthread_join(produce,NULL);
    pthread_join(consume,NULL);


}
