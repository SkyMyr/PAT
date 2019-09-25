#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i,j,a[100];
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int tmp;
    for(i=0;i<k;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
    printf("%d",a[0]);
    for(i=1;i<n;i++)
        printf(" %d",a[i]);
    return 0;
}
