#include<stdio.h>
#include<stdlib.h>

void main ()
{
	int n;
	printf("Enter No of Processes :");
	scanf("%d",&n);
	float arr[n][5],total = 0;
	int j,a[n];
	int sum = 0;
	float tatavg = 0, trbytsavg =0;
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
    int sm = 0;
    int l = 0;
    for(int i = 0 ; i < total ; i++)
    {
        if( i == arr[h][0] && h < n)
        {
            a[k]=h;
            k++;
            h++;

            
            for(int g =l;g<k-1;g++)
            {                     
                for (j = l; j < k-g-1+l; j++)  
                {
                    if (arr[a[j]][1] > arr[a[j+1]][1]) 
                    {
                       int temp = a[j];
                       a[j] = a[j+1];
                       a[j+1] = temp;
            
                    }
                }
            } 

            
          
        }
      

         
        if( sm == i )
        {
            
          
          sm += arr[a[l]][1];
            
          
            l++;
        
  
            
            //i = i + arr[h][1];
            
        
           
         } 
         

        }
        
        
    for(int i =0; i<n; i++)
    {
        printf("%d \n",a[i]);
    }
  
    for(int i=0;i<n;i++)
    {
		sum = sum + arr[a[i]][1];
		arr[a[i]][2] = sum;

		arr[a[i]][3] = arr[a[i]][2] - arr[a[i]][0];
		arr[a[i]][4] = arr[a[i]][3] / arr[a[i]][1];
		tatavg =tatavg + arr[a[i]][3];
		trbytsavg = trbytsavg + arr[a[i]][4];
		
	}

	tatavg = tatavg / n;
	trbytsavg = trbytsavg / n;
	
	printf("Process No \t | Arrival Time \t | Service Time \t | Finishing Time \t | Turn Around Time \t | tr/ts \n");

	for(int i = 0; i < n; i++)
	{
		printf("%d \t \t | %f \t \t | %f \t \t | %f \t \t | %f \t \t | %f \n",a[i],arr[a[i]][0],arr[a[i]][1],arr[a[i]][2],arr[a[i]][3],arr[a[i]][4]);
	}

	printf("\n Mean TAT : %f",tatavg);
	printf("\n Mean tr by ts : %f \n",trbytsavg);
	

}
