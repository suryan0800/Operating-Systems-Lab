#include<stdio.h>
#include<stdlib.h>

void main ()
{
	int n;
	printf("Enter No of Processes :");
	scanf("%d",&n);
	float arr[n][5];
	int i,j,k;
	int sum = 0;
	float tatavg = 0, trbytsavg =0;
	for(i = 0;i < n; i++)
	{
		printf("Enter Arrival Time :");
		scanf("%f",&arr[i][0]);
		printf("Enter Service Time :");
		scanf("%f",&arr[i][1]);

    }

    float temp[5];
    for (i = 0; i < n-1; i++)       
    {
         
        for (j = 0; j < n-i-1; j++)  
        {
            if (arr[j][0] > arr[j+1][0]) 
            {
                for(k = 0;k < 5; k++)
                {
                    temp[k] = arr[j][k];
                    arr[j][k] = arr[j+1][k];
                    arr[j+1][k] = temp[k];
                }
    
            }
        }
    } 
  
    for(int i=0;i<n;i++)
    {
		sum = sum + arr[i][1];
		arr[i][2] = sum;

		arr[i][3] = arr[i][2] - arr[i][0];
		arr[i][4] = arr[i][3] / arr[i][1];
		tatavg =tatavg + arr[i][3];
		trbytsavg = trbytsavg + arr[i][4];
		
	}

	tatavg = tatavg / n;
	trbytsavg = trbytsavg / n;
	
	printf("Process No \t | Arrival Time \t | Service Time \t | Finishing Time \t | Turn Around Time \t | tr/ts \n");

	for(i = 0; i < n; i++)
	{
		printf("%d \t \t | %f \t \t | %f \t \t | %f \t \t | %f \t \t | %f \n",i,arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
	}

	printf("\n Mean TAT : %f",tatavg);
	printf("\n Mean tr by ts : %f \n",trbytsavg);
	

}