#include<stdio.h>
#include<sys/types.h>

void main()
{
	int p[2];
	if(pipe(p) ==-1)
	{
		printf("Pipe Creation Failed ");
		exit(1);
	}
	pid_t pd = fork();
	


	if(pd  >0)
	{	
		printf("I am Parent : %d ",getpid());
		printf("My Parent : %d \n",getppid());
	
	}
	else if(pd ==0)
	{
		printf("I am Child : %d ",getpid());
	
		printf("My Parent : %d \n",getppid());
	

	}
	else 
	{
		printf("Error\n");
	}
}

