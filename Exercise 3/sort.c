#include<stdio.h>

void main()
{

int a[6] = { 1,2,5,3,4,6};
int l = 2;
int k = 5;
  for(int g =l;g<k;g++)
            {                    
                for (int j = l; j <= k-g; j++)  
                {
                    printf("%d,%d\n",a[j], a[j+1]);
                    if (a[j] > a[j+1]) 
                    {
                       int temp = a[j];
                       a[j] = a[j+1];
                       a[j+1] = temp;
            
                    }
                }
            } 

            
            for(int i =l; i<k; i++)
    {
        printf("%d",a[i]);
    }
      printf("\n"); 
        
}  
