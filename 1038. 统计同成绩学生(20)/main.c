/*



本题要求读入N名学生的成绩，将获得某一给定分数的学生人数输出。

输入格式：

输入在第1行给出不超过105的正整数N，即学生总人数。随后1行给出N名学生的百分制整数成绩，中间以空格分隔。最后1行给出要查询的分数个数K（不超过N的正整数），随后是K个分数，中间以空格分隔。

输出格式：

在一行中按查询顺序给出得分等于指定分数的学生人数，中间以空格分隔，但行末不得有多余空格。
输入样例：

10
60 75 90 55 75 99 82 90 75 50
3 75 90 88

输出样例：

3 2 0

*/
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int find(int a[],int n,int x)
{
    int low=0,high=n-1,mid,i,count=0;
    while (low<=high)
    {
        mid = (low+high)/2;
        if (x<a[mid])
            high=mid-1;
        else if (x>a[mid])
            low=mid+1;
        else
            {low=mid;break;}
    }
    //printf("%d\n",a[mid]);
    if(x!=a[mid])
        return count;
    count++;
    for(i=low+1;i<n;i++)
    {
        if(a[i]==x)
            count++;
        else
            break;
    }
    for(i=low-1;i>=0;i--)
    {
        if(a[i]==x)
            count++;
        else
            break;
    }
    return count;
}
int main()
{
    int n,k,i,j,a[100000],b[100000],c[100000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        scanf("%d",&b[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    for(j=0;j<k;j++)
    {
       c[j]=find(a,n,b[j]);
    }

    for(i=0;i<k-1;i++)
    {
        printf("%d ",c[i]);
    }
    printf("%d",c[k-1]);
    //printf("Hello world!\n");
    return 0;
}
