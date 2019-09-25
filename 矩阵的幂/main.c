#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[30][30],b[30][30],c[30][30];
    int n,m;
    int i,j,p;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j];
        }
    }
    if(m==0)
    {
        for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    c[i][j]=1;
                }
            }
    }
    else if(m==1)
    {
        for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    c[i][j]=b[i][j];
                }
            }
    }
    else
    {
        for(p=2;p<=m;p++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                   int k,sum=0;
                    for(k=0;k<n;k++)
                    {
                        sum+=a[i][k]*b[k][j];
                    }
                    c[i][j]=sum;
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    b[i][j]=c[i][j];
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("%d\n",c[i][n-1]);
    }

    return 0;
}
