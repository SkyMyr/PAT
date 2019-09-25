#include <stdio.h>
#include <stdlib.h>
struct SC
{
    int score1,score2,score3,sum;
    char student_id[6],name[11];
}p[100],*aa,*bb;
int cmp(const void *a,const void *b)
{
    aa=(struct SC *)a;
    bb=(struct SC *)b;
    return bb->sum-aa->sum;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d %d %d",p[i].student_id,p[i].name,&p[i].score1,&p[i].score2,&p[i].score3);
        p[i].sum=p[i].score1+p[i].score2+p[i].score3;
    }
    qsort(p,n,sizeof(p[0]),cmp);

    printf("%s %s %d\n",p[0].name,p[0].student_id,p[0].sum);
    return 0;
}
