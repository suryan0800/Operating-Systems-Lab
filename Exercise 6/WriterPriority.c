#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t z,rsem,x,wsem,y;
int data,readcount=0,writecount=0;

void *Reader(void *arg)
{
    while(1){	
    sem_wait(&z);
    sem_wait(&rsem);
    sem_wait(&x);
    readcount++;
    if(readcount == 1)
    { sem_wait(&wsem);  }
    sem_post(&x);
    sem_post(&rsem);
    sem_post(&z);

     printf("Read Data: %d by Reader : %d \n",data,(int)arg);

    sem_wait(&x);
    readcount--;
    if(readcount == 0){sem_post(&wsem);}
    sem_post(&x);

    sleep(2);
    }
}

void *Writer(void *arg)
{
 
    	while(1){ 
        sem_wait(&y);
        writecount++;
        if(writecount == 1)
            sem_wait(&rsem);
        sem_post(&y);
       
        sem_wait(&wsem);
	    data = rand();              
        printf("Data Written : %d by Writer : %d \n",data,(int)arg);
	    sleep(1);
        sem_post(&wsem);
       
        sem_wait (&y);
        writecount--;
        if (writecount == 0) sem_post (&rsem);
        sem_post (&y);

        sleep(5);
        }
}

void main()
{
    pthread_t writer[5],reader[5];
    
    sem_init(&z,0,1);
    sem_init(&rsem,0,1);
    sem_init(&x,0,1);
    sem_init(&y,0,1);
    sem_init(&wsem,0,1);
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
