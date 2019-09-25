#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*char p='5';
    p=(p-48+9)%10+48;
    printf("%c",p);*/
    int i;
    char a[5],t;
    gets(a);
    for(i=0;i<4;i++)
    {
        a[i]=(a[i]-48+9)%10+48;
    }
    t=a[0];
    a[0]=a[2];
    a[2]=t;
    t=a[1];
    a[1]=a[3];
    a[3]=t;
    printf("The encrypted number is ");
    for(i=0;i<4;i++)
    {
        printf("%c",a[i]);
    }

    return 0;
}
