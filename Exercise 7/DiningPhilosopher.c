#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t mutex;
int state[5];
void eat(void *j)
{
   while(1)
   {
        int n = (int)j;

       

     
        printf("Philosopher %d is Thinking \n",n);
        sleep(2);
        
         printf("Philosopher %d is Hungry \n",n);
        sem_wait(&mutex);
         
        if(state[n] == 0 && state[(n+1)%5] == 0)
        {
           
            state[n] = 1;
            state[(n+1)%5] = 1;
        }
        sem_post(&mutex);  
        printf("Philosopher %d is eating \n", n);
        
        sleep(1);
        sem_wait(&mutex);
       
        state[n] = 0;
        state[(n+1)%5] = 0;
        sem_post(&mutex);
        
        
     
   }
    
}
void main()
{
    pthread_t philosopher[5];
  
    sem_init(&mutex, 0, 1);
   
    for(int i = 0; i < 5; i++)
    {
        state[i] = 0;
    }

    for(int i = 0;i < 5; i++)
	{
   		 pthread_create(&philosopher[i],NULL,eat,(void *)i);
		
	}

	
	for(int j = 0;j < 5; j++)
	{
   		
		 pthread_join(philosopher[j],NULL);
	}

}
