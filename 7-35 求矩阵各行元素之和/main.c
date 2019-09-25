#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    for(i=0;i<m;i++)
    {
        int sum=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            sum+=a[i][j];
        }
        printf("%d\n",sum);

    }
    //printf("Hello world!\n");
    return 0;
}
