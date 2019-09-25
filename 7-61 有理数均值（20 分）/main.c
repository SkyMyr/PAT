#include <stdio.h>
#include <stdlib.h>
int gys(int p,int q)
{
    if (q==0) return p;
    int r = p%q;
    return gys(q,r);
}
int main()
{
    int n,i,sumA=0,sumB=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a,b;
        scanf("%d/%d",&a,&b);
        sumA *= b;
        sumA += a*sumB;
        sumB *= b;
        if(i==n-1)
            sumB*=n;
        int ys=gys(sumA,sumB);
        sumA/=ys;
        sumB/=ys;
    }
    if(sumA==0)
        printf("0");
    else if(sumB==1)
        printf("%d",sumA);
    else
        printf("%d/%d",sumA,sumB);
    return 0;
}
