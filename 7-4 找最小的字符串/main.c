#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000
int main()
{
    int i,n;
    char a[M][81];
    scanf("%d",&n);
    getchar();
    gets(a[0]);
    char *m=a[0];
    for(i=1;i<n;i++)
    {
        //getchar();
        //puts(m);
        gets(a[i]);
        //puts(a);
        if(strcmp(m,a[i])>0)
            m=a[i];
    }
    printf("Min is: %s\n", m);
    return 0;
}
