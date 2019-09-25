#include <stdio.h>
#include <stdlib.h>

int n,l,h,m=0;
struct Student
{
    int sNum,sum,de,cai;
}p[100000],a[100000],b[100000],c[100000],d[100000],*aa,*bb;
int cmp(const void *a,const void *b)
{
    aa=(struct Student *)a;
    bb=(struct Student *)b;
    if(bb->sum==aa->sum)
        {
            if(aa->de==bb->de)
                return aa->sNum-bb->sNum;
            return bb->de-aa->de;
        }
        return bb->sum-aa->sum;
}
int main()
{
    int i,j=0;
    int v1=0,v2=0,v3=0,v4=0;
    scanf("%d %d %d",&n,&l,&h);
   // printf("%d %d %d \n",n,l,h);
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&p[j].sNum,&p[j].de,&p[j].cai);
        p[j].sum=p[j].cai+p[j].de;
        if(p[j].de>=l&&p[j].cai>=l)
        {
            m++;
            j++;
        }
    }
    for(i=0;i<m;i++)
    {
        if(p[i].cai>=h&&p[i].de>=h)
        {
            a[v1].cai=p[i].cai;
            a[v1].de=p[i].de;
            a[v1].sNum=p[i].sNum;
            a[v1].sum=p[i].sum;
            v1++;
        }
        else if(p[i].cai<h&&p[i].de>=h)
        {
            b[v2].cai=p[i].cai;
            b[v2].de=p[i].de;
            b[v2].sNum=p[i].sNum;
            b[v2].sum=p[i].sum;
            v2++;
        }
        else if(p[i].de<h&&p[i].cai<h&&p[i].de>=p[i].cai)
        {
            c[v3].cai=p[i].cai;
            c[v3].de=p[i].de;
            c[v3].sNum=p[i].sNum;
            c[v3].sum=p[i].sum;
            v3++;
        }
        else
        {
            d[v4].cai=p[i].cai;
            d[v4].de=p[i].de;
            d[v4].sNum=p[i].sNum;
            d[v4].sum=p[i].sum;
            v4++;
        }
    }
    qsort(a,v1,sizeof(a[0]),cmp);
    qsort(b,v2,sizeof(b[0]),cmp);
    qsort(c,v3,sizeof(c[0]),cmp);
    qsort(d,v4,sizeof(d[0]),cmp);
    printf("%d\n",m);
    for(i=0;i<v1;i++)
    {
        printf("%d %d %d\n",a[i].sNum,a[i].de,a[i].cai);
    }
    for(i=0;i<v2;i++)
    {
        printf("%d %d %d\n",b[i].sNum,b[i].de,b[i].cai);
    }
    for(i=0;i<v3;i++)
    {
        printf("%d %d %d\n",c[i].sNum,c[i].de,c[i].cai);
    }
    for(i=0;i<v4;i++)
    {
        printf("%d %d %d\n",d[i].sNum,d[i].de,d[i].cai);
    }
    //printf("Hello world!\n");
    return 0;
}
