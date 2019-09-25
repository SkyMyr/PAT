#include <stdio.h>
#include <stdlib.h>
struct  Mail_list
{
    char name[12];
    char phoneNumber[50];
    int birth;
}p[10000],*aa,*bb;
int cmp(const void *a,const void *b)
{
    aa=(struct Mail_list *)a;
    bb=(struct Mail_list *)b;
    return aa->birth-bb->birth;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d %s",p[i].name,&p[i].birth,p[i].phoneNumber);
        //scanf("%d",&p[i].birth);
        //scanf("%s",p[i].phoneNumber);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n;i++)
    {
        printf("%s %d %s\n",p[i].name,p[i].birth,p[i].phoneNumber);
    }
    return 0;
}
