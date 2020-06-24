//task challenge 

#include <stdio.h>

int main()
{int tm;
scanf("%d",&tm);
 int ser[tm];
    for (int i=0;i<tm;i++)
    {ser[i]=i+1;

    }
int x;
scanf("%d",&x);int run=-1;
for(int i=0;i<tm-1;i++)
    {run+=x;
    while(run>=(tm-i))
        {
            run=run-tm+i;
        }
        for(int k=run;k<(tm-i);k++)
    {
    ser[k]=ser[k+1];
    }
    ser[tm-i-1]=0;
  
    for(int j=0;j<tm;j++)
    {printf("%d  ",ser[j]);}printf(" run =%d %d\n",run,i);run--;
    }  
printf("%d",ser[0]);


return 0;
}
//done
