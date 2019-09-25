#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[1010];
int main()
{
    gets(a);
    int tmp,i,j,max=0,len = strlen(a);

    for(i=0;i<len;i++)
    {
        tmp=1;
        for(j=1;j<len;j++)
        {
            if(i - j < 0 || i + j >= len || a[i - j] != a[i + j])
                break;
            tmp += 2;
        }
        max = tmp>max?tmp:max;

        tmp=0;
        for( j=1; j<len; j++)
        {
            if(i - j + 1 < 0 || i + j >= len || a[i - j + 1] != a[i + j])
                break;
            tmp += 2;
        }
        max = tmp>max?tmp:max;
    }
    printf("%d",max);
    return 0;
}
