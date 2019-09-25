#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=0,count=1;
    char a[1000];
    gets(a);
    int length=strlen(a);
    while(a[i]==' ')
        i++;
    while(i<length-1)
    {
        if(a[i]==' ' && a[i+1]!=' ')
        {
            count++;
        }
        i++;
    }
    if(i==length)
        count--;
    printf("%d",count);
    return 0;
}
