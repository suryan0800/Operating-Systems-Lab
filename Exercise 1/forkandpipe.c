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
		write(p[1],"Hello ",6);
		sleep(2);
		printf("Parent Ended");
	
	}
	else if(pd ==0)
	{
		char aa[6];
		printf("I am Child : %d ",getpid());
	
		printf("My Parent : %d \n",getppid());
		read(p[0],aa,6);
		printf("The data is : %s",aa);

	}
	else 
	{
		printf("Error\n");
	}
}

