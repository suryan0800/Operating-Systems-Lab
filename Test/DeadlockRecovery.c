#include<stdio.h>
#include<stdlib.h>


int ind = 0 ;


int  checkSafeState(int p,int r,int alloc[][3],int need[][3], int available[],int seq[],int finish[])
{
    
   
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
                    seq[ind] = j;
                    ind++;
                    for(int l = 0; l < r; l++)
                    {
                        available[l] += alloc[j][l];
                    }
                    finish[j] = 1;
                    flag1 = 0;
                }
            }
        }
    }
    
    if(ind == 5)
    {
    printf("No Deadlock \n Safe Sequence \n");
    for(int i = 0; i < p; i++)
    {
        printf("%d  ", seq[i]);
     
    }
    }
    else
    {
        printf("Deadlock occured \n");
    }

    return ind;
}



void main()
{
    int p = 5;
    int r = 3;

   

    
   /*  int   alloc[5][3]= { { 0, 1, 0 }, 
                        { 2, 0, 0 }, 
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };

    
    int   need[5][3] = { { 7, 4, 3 }, 
                      { 4, 2, 2 }, 
                      { 6, 0, 0 }, 
                      { 0, 1, 3 }, 
                      { 4, 3, 1 } };
*/

   int   alloc[5][3]= { { 0, 1, 0 }, 
                        { 2, 0, 0 }, 
                        { 3, 0, 2 }, 
                        { 2, 1, 1 }, 
                        { 0, 0, 2 } };


    
     int   need[5][3] = { { 7, 4, 3 }, 
                      { 1, 2, 2 }, 
                      { 6, 0, 0 }, 
                      { 0, 1, 3 }, 
                      { 4, 3, 1 } };


    int available[3] =  { 3, 3, 2 }; 

    int seq[p], finish[p];

    for(int i = 0 ; i < p ; i++)
    {
        finish[i] = 0;
    }
    

    checkSafeState(p,r,alloc,need,available,seq,finish);
      printf("HEllo %d\n", ind);
         printf("HEllo %d\n", p);
    if(ind < p)
    {
       
        for(int  i=0; i < p; i++)
        {
            if(finish[i] == 0)
            {
                for(int j = 0; j < r; j++)
                {
                    available[j] += alloc[i][j];
                    need[i][j] += alloc[i][j];
                    alloc[i][j] = 0;
                    
                }

                
                checkSafeState(p,r,alloc,need,available,seq,finish);
                 printf("HEllo %d\n", ind);
         printf("HEllo %d\n", p);
                if(ind == p)
                break;
            }
        }

     
    }
    
    
}







