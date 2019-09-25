#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,j,k,q,a[10],sum=0;
    char b[20];
    gets(b);
    int len=strlen(b)+1;
    for(i=0;i<(len/2);i++)
    {
        a[i]=b[2*i]-'0';
    }
    for(j=0;j<i-2;j++)
    {
        for(k=j+1;k<i-1;k++)
        {
            for(q=k+1;q<i;q++)
            {
               sum+=222*(a[j]+a[k]+a[q]);
            }
        }
    }
    printf("%d",sum);
    return 0;
}
