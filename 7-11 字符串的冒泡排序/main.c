#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    char a[100][11],b[11];
    int i,j,n,m,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        if(strcmp(a[j],a[j+1])>0)
        {
            strcpy(b,a[j+1]);
            strcpy(a[j+1],a[j]);
            strcpy(a[j],b);
        }
        if(i+1==k)
        {
            for(m=0;m<n;m++)
                printf("%s\n",a[m]);
            break;
        }


    }
    return 0;
}
