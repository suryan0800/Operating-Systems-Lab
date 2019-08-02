#include<stdio.h>
#include<stdlib.h>

void main ()
{
	int n;
	printf("Enter No of Processes :");
	scanf("%d",&n);
	float arr[n][7];
    int total = 0;
	int j;
	int sum = 0;
    int quantum ;

    printf("Enter Quantum : ");
    scanf("%d",&quantum);
	float tatavg = 0, trbytsavg =0, waitavg = 0;
	for(int i = 0;i < n; i++)
	{
		printf("Enter Arrival Time :");
		scanf("%f",&arr[i][0]);
		printf("Enter Service Time :");
		scanf("%f",&arr[i][1]);
        total = total + arr[i][1];
    }

    

    float temp[5];
    for (int i = 0; i < n-1; i++)       
    {
         
        for (j = 0; j < n-i-1; j++)  
        {
            if (arr[j][0] > arr[j+1][0]) 
            {
                for(int k = 0;k < 5; k++)
                {
                    temp[k] = arr[j][k];
                    arr[j][k] = arr[j+1][k];
                    arr[j+1][k] = temp[k];
                }
    
            }
        }
    }

   

    int k = 0;
    int h = 0;
    float sm = 0;
    int l = 0;
    float service[n];
    int queue[total];   
    int q = 0;
    int token;
    int flag = 0;
    

    for(int i = 0 ; i < n; i++)
    {
        service[i] = arr[i][1];
    }

    printf("%d \n",total);
    for(int i = 0 ; i < total ; i++)
    {
        if(arr[h][0] == i && h < n)
        {

             
            queue[q] = h;
            h++;
            q++;
           
                       
        }

        if(flag == 1)
        {
            queue[q] = token;
                q++;
                l++; 
            flag = 0;
        }
      
        if(sm == i && l < q)
        {
            if(service[queue[l]] == arr[queue[l]][1])
            {
                printf("Starting Time : %d Process : %d \n",i,queue[l]);
                arr[queue[l]][2] = i;
            }
            
            if(service[queue[l]] > quantum )
            {
               

                printf("Process : %d \n",queue[l]); 
                sm += quantum; 
                
                service[queue[l]] -= quantum;

                token = queue[l];
                flag = 1;
               
               /* queue[q] = queue[l];
                q++;
                l++;            
                
               */ 
            
            }
            else
            {
                 printf("Process : %d \n",queue[l]); 
                sm += service[queue[l]];
                service[queue[l]] = 0;
                arr[queue[l]][3] = sm;
                l++;
                printf("Finish Time : %f \n",sm);
                
            }
        }

    }
    
 
   for(int i =0; i<n; i++)
    {
        printf("%f \n",arr[i][0]);
    }
  
    for(int i=0;i<n;i++)
    {
		 
        arr[i][4] = arr[i][3] - (arr[i][0] + arr[i][1]);
        
       
		arr[i][5] = arr[i][3] - arr[i][0];

		arr[i][6] = arr[i][4] / arr[i][1];
        waitavg = waitavg + arr[i][4];
		tatavg =tatavg + arr[i][5];
		trbytsavg = trbytsavg + arr[i][6];
        
		
	}

   
    waitavg = waitavg /n;
	tatavg = tatavg / n;
	trbytsavg = trbytsavg / n;
	
	printf("Process No \t | Arrival Time \t | Service Time \t | Starting Time \t | Finishing Time \t | Waiting Time \t | Turn Around Time \t | tr/ts \n");

	for(int i = 0; i < n; i++)
	{
		printf("%d \t \t | %f \t \t | %f \t \t | %f \t \t | %f \t \t | %f \t \t | %f \t \t | %f \t \t \n",i,arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5],arr[i][6]);
	}
    
    printf("\n Mean Waiting Time : %f \n",waitavg);
	printf("\n Mean TAT : %f",tatavg);
	printf("\n Mean tr by ts : %f \n",trbytsavg);
	

}
