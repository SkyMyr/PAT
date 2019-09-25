#include <stdio.h>
#include <stdlib.h>

struct person
{
    int score;
    char name[10];
}p[10000];
int main()
{
    int i,n,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d",p[i].name,&p[i].score);
        sum+=p[i].score;
    }
    int avg=sum/n/2;
    //printf("%d",avg);
    int min=100,m=-1;
    for(i=0;i<n;i++)
    {
        if(abs(avg-p[i].score)<min)
        {
            min=abs(avg-p[i].score);
            m=i;
        }
    }
    printf("%d %s",avg,p[m].name);
    return 0;
}
