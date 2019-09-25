#include<stdio.h>
#include <math.h>
int num[100000] ;
int main()
{
    int a,n,carry=0,i,k=1,l,tmp=1;
    scanf("%d %d",&a,&n);
    if(n==0)
        printf("0");
    else
    {
        for(i=n;i>=1;i--)
        {
            num[i] = (i*a+carry)%10;
            carry =(i*a+carry)/10;
            k++;
            if(carry&&i==1)
            {
                num[0]=carry;
                tmp = 0;
            }
        }
        for( i = tmp ; i < k ; i ++ )
            printf("%d",num[i]);
    }
    return 0;
}
