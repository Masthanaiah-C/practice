//task challenge

#include <stdio.h>

int main()
{int tm;
scanf("%d",&tm);
 int ser[tm];
    for (int i=0;i<tm;i++)
    {scanf("%d",&ser[i]);

    }
int x;
scanf("%d",&x);int run=-1;
for(int i=0;i<tm-1;i++)
    {run+=x;
    while(run>tm-i-1)
        {
            run=run-tm-i-1;
        }
        for(int k=run;k<tm-i;k++)
    {
    ser[k]=ser[k+1];
    }
    ser[tm-i-1]=0;
    run--;
    }
printf("%d",ser[0]);
int test=0;int i=0;

return 0;
}