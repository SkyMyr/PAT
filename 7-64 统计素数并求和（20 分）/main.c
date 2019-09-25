#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int m,n,i,j,sum=0,count=0;
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++)
    {
        if(i==1)
            continue;
        for(j=2;j<sqrt(i);j++)
        {
            if(i%j==0)
                break;
        }
        if(j>sqrt(i))
        {
            //printf("%d\n",i);
            count++;
            sum+=i;
        }
    }
    printf("%d %d",count,sum);
    return 0;
}
