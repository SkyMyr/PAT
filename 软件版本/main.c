#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100],b[100];
    gets(a);
    gets(b);
    if(strcmp(a,b)>0)
        puts(a);
    else
        puts(b);
    return 0;
}
