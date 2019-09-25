#include <stdio.h>
#include <stdlib.h>
int a[1000000];
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=i;
    }
    printf("%d\n",sum*6);
    return 0;
}
