#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i,k1=0,k2=0,k3=0,k4=0;
    char a[33];
    gets(a);
    for(i=0;i<8;i++)
    {
        if(a[i]!='0')
            k1+=pow(2,7-i);
    }
    for(i=8;i<16;i++)
    {
        if(a[i]!='0')
            k2+=pow(2,15-i);
    }
    for(i=16;i<24;i++)
    {
        if(a[i]!='0')
            k3+=pow(2,23-i);
    }
    for(i=24;i<32;i++)
    {
        if(a[i]!='0')
            k4+=pow(2,31-i);
    }
    printf("%d.%d.%d.%d",k1,k2,k3,k4);
    return 0;
}
