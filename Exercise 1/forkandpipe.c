#include<stdio.h>
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


	if(pd > 0)
	{	
		
		printf("I am Parent : %d ",getpid());
		printf("My Parent : %d \n",getppid());
        printf("Enter Some Char \n");
        gets(str);
       
		write(p[1],str,strlen(str));
		sleep(2);
		printf("Parent Ended");
	
	}
	else if(pd ==0)
	{
		char aa[100];
		printf("I am Child : %d ",getpid());
	
		printf("My Parent : %d \n",getppid());
		read(p[0],aa,100);
		printf("The data is : %s \n",aa);

	}
	else 
	{
		printf("Error\n");
	}
}

