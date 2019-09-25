#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,len=0;
    char a;
    char s[10],s2[10];
    a=getchar();
    for(i=0;a!='\n';i++)
    {
        if(a>='0'&&a<='9')
        {
            s[len]=a;
            len++;
        }
        a=getchar();
    }
    for(i=0;i<len;i++)
    {
        if(s[i]!='0')
        {
            break;
        }
    }
    if(len==1)
        printf("%c",s[0]);
    else
    {
        for(;i<len;i++)
        printf("%c",s[i]);
    }
    return 0;
}
