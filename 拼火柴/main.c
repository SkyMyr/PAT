#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
struct Node
{
    int value,flag;
}p[20];
int main()
{
    int n,i,j,k,q;
    scanf("%d",&n);
    if(n>=1&&n<=100)
        for(q=0;q<n;q++)
        {
            int count=1,m,a[20];
            scanf("%d",&m);
            for(i=0;i<m;i++)
            {
                scanf("%d",&a[i]);
            }
            if(m==4)
            {
                if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3])
                    printf("yes\n");
                else
                    printf("no\n");
            }
            else
            {
                qsort(a,m,sizeof(int),cmp);
                for(i=0;i<m;i++)
                {
                    p[i].value=a[i];
                    p[i].flag=1;
                }
                for(i=m-1;i>=3;i--)
                {
                    for(j=0;j<i;j++)
                    {
                        for(k=0;k<i;k++)
                        {
                            if(a[j]+a[k]==a[i]&&j!=k&&p[j].flag==1&&p[k].flag==1)
                            {
                                count++;
                                p[j].flag=0;
                                p[k].flag=0;
                            }
                            else if(a[k]==a[i]&&p[k].flag==1)
                            {
                                count++;
                                p[k].flag=0;
                            }
                        }

                    }

                }
                if(count>=4)
                {
                    printf("yes\n");
                }
                else
                    printf("no\n");
            }
        }
    return 0;
}
