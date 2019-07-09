#include<stdio.h>
#include<sys/types.h>

void main()
{
	
	pid_t pd = fork();
	


	if(pd > 0)
	{	
		
		printf("I am Parent : %d \n",getpid());
		printf("My Parent : %d \n",getppid());
		
		printf("Parent Ended \n");
	
	}
	else if(pd == 0)
	{
		char aa[6];
		printf("I am Child : %d \n",getpid());
	
		printf("My Parent : %d \n",getppid());
		printf("Child Ended \n");

	}
	else 
	{
		printf("Error\n");
	}
}

