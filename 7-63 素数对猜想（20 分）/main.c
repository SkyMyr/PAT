#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int a[100000];
int main()
{
    int n,i,t,j,k;
    scanf("%d",&n);
    k=0;
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                break;
        }
        if(j>sqrt(i))
        {
            a[k++]=i;
        }
    }
    //printf("%d\n",k);
    t=0;
    for(i=1;i<k;i++)
    {
        //printf("%d\n",a[i]);
        if(a[i+1]-a[i]==2){
            //printf("%d-",a[i]);
            t++;
        }
    }
    printf("%d",t);
    return 0;
}
