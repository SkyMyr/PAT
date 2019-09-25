#include <stdio.h>
#include <stdlib.h>
//矩阵a*b和b*a不一样！
int main()
{
    int a[50][50],b[50][50],c[50][50];
    int n,arf,t;
    int i,j,p,k,q;
    scanf("%d",&t);
    scanf("%d%d",&n,&arf);
    for(p=0;p<t;p++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                if(p==0)
                    b[i][j]=a[i][j];
            }
        }
        if(p>0)
        {
            for(k=0;k<n;k++)
            {
                for(q=0;q<n;q++)
                {
                    int h,sum=0;
                    for(h=0;h<n;h++)
                    {
                        sum+=b[k][h]*a[h][q];
                        //printf("%d %d sum=:%d\n",a[k][h],b[h][q],sum);
                    }
                    c[k][q]=sum;
                }
            }
            for(k=0;k<n;k++)
            {
                for(q=0;q<n;q++)
                {
                    b[k][q]=c[k][q];
                }
            }
        }
    }
    if(arf%360==0)
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("%d\n",c[i][n-1]);
    }
    else if(arf%360==90)
    {
        for(i=n-1;i>=0;i--)
        {
            for(j=0;j<n-1;j++)
            {
                printf("%d ",c[j][i]);
            }
            printf("%d\n",c[n-1][i]);
        }
    }
    else if(arf%360==180)
    {
        for(i=n-1;i>=0;i--)
        {
            for(j=n-1;j>0;j--)
            {
                printf("%d ",c[i][j]);
            }
            printf("%d\n",c[i][0]);
        }
    }
    else if(arf%360==270)
    {
        for(j=0;j<n;j++)
        {
            for(i=n-1;i>0;i--)
            {
                printf("%d ",c[i][j]);
            }
            printf("%d\n",c[0][j]);
        }
    }

    return 0;
}
