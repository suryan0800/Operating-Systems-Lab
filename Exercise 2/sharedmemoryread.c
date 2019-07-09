#include<stdio.h>

//Inter Process Communication using Shared Memory
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include<string.h>

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

    
    printf("Data Read: %s \n",str);
    strcpy(str,"#");
    printf("Data Written : %s \n",str);

    shmdt(str);
 //   shmctl(shmid,IPC_RMID,NULL); 
}   
