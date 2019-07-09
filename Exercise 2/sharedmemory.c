#include<stdio.h>

//Inter Process Communication using Shared Memory
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <unistd.h>

void main()
{
    char *str;
    key_t key = ftok("shmfile",65);
    int shmid;
    if((shmid = shmget(key,27,0666|IPC_CREAT)) < 0)
    {
        printf("Error in Getting Shared Memory");
    }

    if((str = shmat(shmid,NULL,0)) == NULL)
    {
        printf("Error in Sharing created Memory " );
    }

    for(int i =0; i<26; i++)
    {
        str[i] = (char)(i+65);
    }

    printf("Data Written: %s \n",str);

     while(strcmp(str,"#") != 0)
    {
       sleep(2); 
        
    } 
    printf("Data Read : %s \n",str);
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL); 
}   
