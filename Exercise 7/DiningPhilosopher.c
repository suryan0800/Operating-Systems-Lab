#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t mutex[5],room;

void eat(void *j)
{
   while(1)
   {
        int n = (int)j;

       

     
        printf("Philosopher %d is Thinking \n",n);
        sleep(2);
        
        
        sem_wait(&room);
         printf("Philosopher %d is Hungry \n",n);
        sem_wait(&mutex[n]);
        sem_wait(&mutex[(n+1)%5]);
         
       
        printf("Philosopher %d is eating \n", n);
        
        sleep(1);

        sem_post(&mutex[(n+1)%5]);
        sem_post(&mutex[n]);
        sem_post(&room);
       
        
     
   }
    
}
void main()
{
    pthread_t philosopher[5];
    for(int i = 0; i < 5; i++)
    {
        sem_init(&mutex[i], 0, 1);
    }

    sem_init(&room,0,4);
    

    for(int i = 0;i < 5; i++)
	{
   		 pthread_create(&philosopher[i],NULL,eat,(void *)i);
		
	}

	
	for(int j = 0;j < 5; j++)
	{
   		
		 pthread_join(philosopher[j],NULL);
	}

}
