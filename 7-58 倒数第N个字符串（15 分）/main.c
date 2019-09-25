#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
    int sum=1,i;
    for( i=0;i<x;i++)
    {
        sum=sum*26;
    }
    return sum;
}
int main()
{
    int l,i,n;
    char a[10];
    scanf("%d %d",&l,&n);
    int ll=f(l);
    int x=ll-n,j=0;
    for( i=l-1;i>=0;i--)
    {
        a[j]=x/f(i)+'a';
        x=x%f(i);
        j++;
    }
    for( i=0;i<l;i++)
        printf("%c",a[i]);
    return 0;
}
