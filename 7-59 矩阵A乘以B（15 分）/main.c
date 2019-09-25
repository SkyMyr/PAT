#include<stdio.h>

int main()
{
    int a[101][101];
    int b[101][101];
    int i,j,k;
    int p,q;
    int x,y;
    //输入矩阵1
    scanf("%d%d",&p,&q);
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d",&a[i][j]);

    //输入矩阵2
    scanf("%d%d",&x,&y);
    for(i=0; i<x; i++)
        for(j=0; j<y; j++)
            scanf("%d",&b[i][j]);

    //如果矩阵1的列不等于矩阵2的行，则出错退出，否则进行矩阵的乘法
    if(q!=x)
    {
        printf("Error: %d != %d\n",q,x);
    }
    else
    {
        printf("%d %d\n",p,y);
        //进行矩阵的乘法
        for(i=0; i<p; i++)
        {
            for(j=0; j<y; j++)
            {
                int sum=0;
                for(k=0; k<q; k++)
                    sum += a[i][k]*b[k][j];
                if(j < y-1)
                    printf("%d ",sum);
                else
                    printf("%d\n",sum);
            }
        }
    }
    return 0;
}
