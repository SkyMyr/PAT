#include<stdio.h>

int main()
{
    int a[101][101];
    int b[101][101];
    int i,j,k;
    int p,q;
    int x,y;
    //�������1
    scanf("%d%d",&p,&q);
    for(i=0; i<p; i++)
        for(j=0; j<q; j++)
            scanf("%d",&a[i][j]);

    //�������2
    scanf("%d%d",&x,&y);
    for(i=0; i<x; i++)
        for(j=0; j<y; j++)
            scanf("%d",&b[i][j]);

    //�������1���в����ھ���2���У�������˳���������о���ĳ˷�
    if(q!=x)
    {
        printf("Error: %d != %d\n",q,x);
    }
    else
    {
        printf("%d %d\n",p,y);
        //���о���ĳ˷�
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
