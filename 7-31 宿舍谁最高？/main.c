#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SC
{
    int height,weight,dormNum;
    char name[20];
}p[1000000];
int main()
{
    //printf("%d",p[0].height);
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int dorm,height,weight;
        char name[20];
        scanf("%d %s %d %d",&dorm,name,&height,&weight);
        if(height>p[dorm].height)
        {
            p[dorm].height=height;
            p[dorm].weight=weight;
            strncpy(p[dorm].name,name,sizeof(p[dorm].name));
            //p[dorm].name=name;
        }
    }
    for(i=0;i<999999;i++)
    {
        if(p[i].height!=0)
            printf("%06d %s %d %d\n",i,p[i].name,p[i].height,p[i].weight);
    }
    return 0;
}
