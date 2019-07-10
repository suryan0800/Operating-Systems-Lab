#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buf
{
    long msg_type;
    char msg_text[100];
}message;

void main()
{
    key_t key =3333;
    int msgid;

    if((msgid = msgget(key,0666|IPC_CREAT)) < 0)
    {
        printf("Error");
        exit(1);
    }

    message.msg_type = 1;
    printf("Enter Text \n");
    gets(message.msg_text);
    
    msgsnd(msgid,&message,sizeof(message),0);

    printf("Data send is : %s \n",message.msg_text);
}
