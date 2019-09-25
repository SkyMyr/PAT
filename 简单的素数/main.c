#include <stdio.h>
#include <stdlib.h>
int IsPrime(int a)
{
    int i;
    for(i=2;i<a;i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int a;
    scanf("%d",&a);
    if(IsPrime(a))
        printf("yes");
    else
        printf("no");
    return 0;
}
