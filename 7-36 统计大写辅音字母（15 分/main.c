#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[81];
    gets(a);
    int i,count=0,l=strlen(a);
    for(i=0;i<l;i++)
    {
        if(a[i]>='B'&&a[i]<='Z'&&a[i]!='E'&&a[i]!='I'&&a[i]!='O'&&a[i]!='U')
            count++;
    }
    printf("%d\n",count);
    return 0;
}
