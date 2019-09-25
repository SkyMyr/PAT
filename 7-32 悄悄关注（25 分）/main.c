#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct followList
{
    char id[5];
    int number;
}p[10000],*aa,*bb;
int cmp(const void *a,const void *b)
{
    aa=(struct followList *)a;
    bb=(struct followList *)b;
    return bb->number-aa->number;
}
int comp(const void *a,const void *b)
{
    aa=(struct followList *)a;
    bb=(struct followList *)b;
    return strcmp(aa->id,bb->id);
}
char a[5000][5];
int main()
{
    int n,m,i,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        //printf("%s\n",a[i]);
    }
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%s %d",p[i].id,&p[i].number);
        sum+=p[i].number;
    }
    int avg=sum/m;
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(p[i].number<=avg)
            break;
    }
    qsort(p,i,sizeof(p[0]),comp);
    int j,k,count=0;
    for(j=0;j<i;j++)
    {
        int flag = 0;
        for(k=0;k<n;k++)
        {
            if(strcmp(p[j].id,a[k])==0)
            {
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            printf("%s\n",p[j].id);
            count++;
        }
    }
    if(count==0)
    printf("Bing Mei You");
    return 0;
}
