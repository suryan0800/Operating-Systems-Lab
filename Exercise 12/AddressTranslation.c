#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int lrange,prange,psize;
    
    printf("Enter Logical Page Range \n");
    scanf("%d",&lrange);
    
    printf("Enter Physical Frame Range \n");
    scanf("%d",&prange);

    printf("Enter Page Size \n");
    scanf("%d",&psize);

    int ptable[lrange];
    
    for(int i =0 ; i<lrange;i++)
    {
        int flag = 0;
        int rd;
        while(flag == 0)
        {
            flag = 1;
            rd = rand()%prange;
            for(int j = 0; j < i;j++)
            {
                if(ptable[j] == rd){    flag = 0;break; }
            }
        }
        ptable[i] = rd;
    }
    
    printf("Page Table \n");
    printf("Page \t Mapping \n");
    for(int i = 0; i < lrange;i++)
    {
        printf(" %d \t %d \n",i,ptable[i]);
    }

    int pno;
    printf("Enter Page No \n");
    scanf("%d",&pno);

    printf("The Mapped Physical Memory is %d \n",(ptable[pno]*psize));

}











