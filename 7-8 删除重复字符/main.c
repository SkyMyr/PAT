#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void*a,const void *b)
{
    return(strcmp((char*)a,(char*)b));
}
int main()
{
    char a[81];
    int i;
    gets(a);
    int length=strlen(a);
    qsort(a,length,sizeof(a[0]),cmp);
    puts(a);
    printf("%c",a[0]);
    for(i=1;i<length-1;i++)
    {
        if(a[i]!=a[i-1])
            printf("%c",a[i]);
    }
    //printf("Hello world!\n");
    return 0;
}
