#include<stdio.h>
#include<stdlib.h>

void main()
{
    int p = 5;
    int r = 3;

  

    
     int   alloc[5][3]= { { 0, 1, 0 }, 
                        { 2, 0, 0 }, 
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };

    
    int   max[5][3] = { { 7, 5, 3 }, 
                      { 3, 2, 2 }, 
                      { 9, 0, 2 }, 
                      { 2, 2, 2 }, 
                      { 4, 3, 3 } };

    int available[3] =  { 3, 3, 2 }; 

    int finish[p] , seq[p] , index = 0;

    int need[p][r];

    for(int i=0; i< p; i++)
    {
        for(int j = 0 ; j < r; j ++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        
        }
    }

    for(int i = 0 ; i < p ; i++)
    {
        finish[i] = 0;
    }
    int flag = 0;
    int flag1  = 0;
    while(flag1 == 0)
    {
        flag1 = 1;
        for(int j = 0; j < p; j++)
        {
            if(finish[j] == 0)
            {
                flag = 0;
                for(int k = 0; k < r; k++)
                {
                    if(need[j][k] > available[k])
                    {
                        flag = 1;
                        break;
                    }
                }

                if(flag == 0 )
                {
                    seq[index] = j;
                    index++;
                    for(int l = 0; l < r; l++)
                    {
                        available[l] += need[j][l];
                    }
                    finish[j] = 1;
                    flag1 = 0;
                }
            }
        }
    }

    for(int i = 0; i < p; i++)
    {
        printf("%d  ", seq[i]);
    }
}














