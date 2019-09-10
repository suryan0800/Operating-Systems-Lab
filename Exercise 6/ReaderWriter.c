#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t sem_write,sem_read;
int data,reader_count = 0;

void *Reader(void *arg)
{
    	
        sleep(0.5);
        sem_wait(&sem_read);
	reader_count ++;   
	if(reader_count == 1)
	{
		sem_wait(&sem_write);
	}  
  
	sem_post(&sem_read);
  
        printf("Read Data: %d by Reader : %d \n",data,(int)arg);
	
	sem_wait(&sem_read);
	//sleep(1);
	reader_count--;
	if(reader_count == 0)
	{
		sem_post(&sem_write);	
	}
	
        sem_post(&sem_read);
    
}

void *Writer(void *arg)
{
 
    	 
        sem_wait(&sem_write);
       
	data = rand();              
        printf("Data Written : %d by Writer : %d \n",data,(int)arg);
	sleep(1);
        sem_post(&sem_write);
        
}

void main()
{
    pthread_t writer[5],reader[5];
    
    sem_init(&sem_write,0,1);
    sem_init(&sem_read,0,1);
	for(int i = 0;i < 5; i++)
	{
   		 pthread_create(&writer[i],NULL,Writer,(void *)i);
		 pthread_create(&reader[i],NULL,Reader,(void *)i); 
    	}
	
	
	for(int j = 0;j < 5; j++)
	{
   		 pthread_join(writer[j],NULL);
		 pthread_join(reader[j],NULL);
	}

}
