#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,x,m,n,count,a[10000];
    scanf("%d",&m);
    n=3;
    for(i=1;i<=m;i++)
      a[i]=i;
    count=m;
    x=0;
    for(i=0;count>1;i++)
    {
     if(a[i%m+1]!=-1)
       {
       x++;
       }
     if(x==n && a[i%m+1]!=-1)
       {
       a[i%m+1]=-1;
       count--;
       x=0;
       }
     }
    for(i=1;i<=m;i++)
      if(a[i]!=-1)
        printf("%d\n",i);
    return 0;
}
