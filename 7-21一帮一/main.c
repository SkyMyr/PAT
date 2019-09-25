#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,a[50],i;
    char b[50][10];
    int j;
    scanf("%d",&N);
    for(i=0; i<N; i++)
    {
        scanf("%d",&a[i]);
        scanf("%s",b[i]);
    }
    for(i=0; i<N; i++)
    {
        for(j=N-1; j>=0; j--)
        {
            if(a[i]!=a[j]&&a[i]<=1&&a[j]<=1)
            {
                a[i]=2;
                a[j]=2;
                printf("%s %s\n",b[i],b[j]);
                break;
            }
        }
    }
    return  0;
}
