#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[10010],b[10010];
int judge(char e)
{
    int i,n=strlen(b);
    for(i=0;i<n;i++)
    {
        if(e==b[i])
            return 0;
    }
    return 1;
}
int main()
{
    int i;
    gets(a);
    gets(b);
    int length=strlen(a);
    for(i=0;i<length;i++)
    {
        if(judge(a[i]))
            printf("%c",a[i]);
    }
    return 0;
}
