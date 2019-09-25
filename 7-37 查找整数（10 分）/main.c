#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n,x,flag=0;
    scanf("%d %d",&n,&x);
    for(i=0;i<n;i++)
    {
        int y;
        scanf("%d",&y);
        if(x==y)
        {
            printf("%d",i);
            flag=1;
            break;
        }
    }
    if(flag==0)
    printf("Not Found");
    return 0;
}
