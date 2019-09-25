#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[6][80];
    int i,j,b[5]={0,1,2,3,4};
    for(i=0;i<5;i++)
    {
        scanf("%s",a[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(strcmp(a[i],a[j])>0)
            {
                int t=b[i];
                b[i]=b[j];
                b[j]=t;
                strcpy(a[5],a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],a[5]);
            }
        }
    }
    printf("After sorted:\n");
    for(i=0;i<5;i++)
    {
        printf("%s\n",a[i]);
    }
    //puts(a1);puts(a5);
    return 0;
}
