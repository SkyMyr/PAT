#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct book
{
    char name[300];
    double price;
}now,max,min;
int main()
{
    max.price=0;
    min.price=999999;
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        getchar();
        gets(now.name);
        scanf("%lf",&now.price);
        if(now.price>max.price)
        {
            strcpy(max.name,now.name);
            max.price=now.price;
        }
        if(now.price<min.price)
        {
            strcpy(min.name,now.name);
            min.price=now.price;
        }
    }
    printf("%.2lf, %s\n%.2lf, %s",max.price,max.name,min.price,min.name);
    return 0;
}
