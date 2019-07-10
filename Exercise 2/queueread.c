#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buff
{
    long msg_type;
    char msg_text[100];
}message;

void main()
{
    key_t key = 3333;
    int msgid;

    if((msgid = msgget(key,0666|IPC_CREAT)) <0)
    {
        printf("Error \n");
        exit(1);
    }

    msgrcv(msgid,&message,sizeof(message),1,0);
    
    printf("Data Received : %s \n",message.msg_text);

    //msgctl(msgid,IPC_RMID,NULL);
}
