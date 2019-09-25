#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[81];
    gets(a);
    int i,length=strlen(a);
    for(i=length-1;i>=0;i--)
    {
        printf("%c",a[i]);
    }
    //printf("Hello world!\n");
    return 0;
}
