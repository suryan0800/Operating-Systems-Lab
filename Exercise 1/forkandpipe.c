#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

void main()
{
	int p[2];
	if(pipe(p) ==-1)
	{
		printf("Pipe Creation Failed ");
		exit(1);
	}
	pid_t pd = fork();
	char str[100];
    char str1[100];

	if(pd > 0)
	{	
		
		printf("I am Parent : %d ",getpid());
		printf("My Parent : %d \n",getppid());
        printf("Enter Some Char \n");
        gets(str);
       
		write(p[1],str,strlen(str));
		sleep(2);
        
        read(p[0],str1,100);
        printf("The Data from Client to Parent is : %s \n",str1);
		printf("Parent Ended \n");
	
	}
	else if(pd ==0)
	{
		char aa[100];
        read(p[0],aa,100);
		printf("I am Child : %d ",getpid());
	
		printf("My Parent : %d \n",getppid());
		
		printf("The Data from Parent to Client is : %s \n",aa);
        write(p[1],"Why Sastra",strlen("Why Sastra"));
	}
	else 
	{
		printf("Error\n");
	}
}

