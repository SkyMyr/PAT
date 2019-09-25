#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[20000],b[20000];
	int i,j,n,m;;
    gets(a);
    gets(b);
    n=strlen(a);
    m=strlen(b);
    int flag=1;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(a[i]==b[j])
            {
                flag=0;
                break;
            }
        }
        if (flag)
        {
            printf("%c",a[i]);
        }
        flag=1;
    }
    return 0;
}
