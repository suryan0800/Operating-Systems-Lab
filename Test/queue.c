#include<stdio.h>
#include<stdlib.h>

void main()
{

	int n;
	printf("Enter No of Processes : \n");
	scanf("%d",&n);
	float arr[n][7];
	float tatavg = 0;
	int i,j,k;
	int quantum1 = 1;
	int quantum2 = 2;
 i =0; j = 0; k = 0;
	for( i = 0; i < n; i ++)
	{
		printf("Enter Arrival \n");
		scanf("%f",&arr[i][0]);
		printf("Enter Service \n");
		scanf("%f",&arr[i][1]);
		
	}
	
	for( i = 0; i < n-1; i++)
	{
		for( j = 0; j < n- i - 1; j++)
		{
			if(arr[j][0] > arr[j+1][0])
			{
				for( k = 0; k < 7; k++)
				{
					int temp = arr[j][k];
					arr[j][k] = arr[j+1][k];
					arr[j+1][k] = temp;
				}
			}
		}
	}

	int queue1[50];
	int queue2[50];
	float service[n];
	int sm = arr[0][0];
	int front1 = 0,front2 = 0,rear1 = 0,rear2 = 0, h = 0 ;
	i =0; j = 0; k = 0;
	for( i = 0; i < n; i++)
	{
		service[i] = arr[i][1];
	}

	for( i = 0; (h < n || front1 < rear1 || front2 < rear2); i++)
	{
		if(h < n && arr[h][0] == i)
		{
			queue1[rear1] = h;
			rear1++;
			h++;
		}
      
		if(sm == i && front1 < rear1)
		{
          
			if(service[queue1[front1]] == arr[queue1[front1]][1])
			{
				arr[queue1[front1]][3] = i;
			}
			if(service[queue1[front1]] > quantum1)
			{
				sm += quantum1;
				printf("Gunt Chart Process  %d \n" , queue1[front1]);
				service[queue1[front1]] -= quantum1;
				queue2[rear2] = queue1[front1];
				rear2++;
				front1++;
			}
			else
			{
                
				sm += service[queue1[front1]];
				printf("Gunt Chart Process  %d \n" , queue1[front1]);
				arr[queue1[front1]][4] = sm;
				arr[queue1[front1]][5] = arr[queue1[front1]][3] - arr[queue1[front1]][0];
				arr[queue1[front1]][6] = arr[queue1[front1]][4] - arr[queue1[front1]][0];
				tatavg += arr[queue1[front1]][6];
				service[queue1[front1]] = 0;
				front1++;
			}
		}
		else if(sm == i && front2 < rear2)
		{
       
			if(service[queue2[front2]] > quantum2)
			{
				sm += quantum2;
				printf("Gunt Chart Process  %d \n" , queue2[front2]);
				service[queue2[front2]] -= quantum2;
				queue2[rear2] = queue2[front2];
				rear2++;
				front2++;
			}
			else
			{
				sm += service[queue2[front2]];
				printf("Gunt Chart Process  %d \n" , queue2[front2]);
				arr[queue2[front2]][4] = sm;
				arr[queue2[front2]][5] = arr[queue2[front2]][3] - arr[queue2[front2]][0];
				arr[queue2[front2]][6] = arr[queue2[front2]][4] - arr[queue2[front2]][0];
				tatavg += arr[queue2[front2]][6];
				service[queue2[front2]] = 0;
				front2++;
			}
		}
	}

     for(int i = 0; i < 8; i++)
    {
        printf("%d \t ",queue1[i]);
    }
    printf("\n");
    for(int i = 0; i < 9; i++)
    {
        printf("%d \t ",queue2[i]);
    }

    printf("\n");
	tatavg = tatavg / n;

	i =0; j = 0; k = 0;
	for( i = 0 ; i < n; i++)
	{	
		printf("%d \t ",i);
		for( j = 0 ; j < 7; j++)
		{
			printf("%f \t ",arr[i][j]);
		}
		printf("\n");
	}

	printf("Mean tat : %f " ,tatavg);
}








