/*


����Ҫ����д������Ѹ����ķ��Ŵ�ӡ��ɳ©����״���������17����*����Ҫ�����и�ʽ��ӡ

*****
 ***
  *
 ***
*****

��ν��ɳ©��״������ָÿ��������������ţ����з������Ķ��룻�������з�������2���������ȴӴ�С˳��ݼ���1���ٴ�С����˳���������β��������ȡ�

��������N�����ţ���һ�����������һ��ɳ©��Ҫ���ӡ����ɳ©���õ������ܶ�ķ��š�

�����ʽ��

������һ�и���1��������N��<=1000����һ�����ţ��м��Կո�ָ���

�����ʽ��

���ȴ�ӡ���ɸ���������ɵ�����ɳ©��״�������һ�������ʣ��û�õ��ķ�������
����������

19 *

���������

*****
 ***
  *
 ***
*****
2

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,i,p,q,k1,p1,q1,j,n,num=1,leave;
    char lable;
    scanf("%d %c",&n,&lable);
    if(n==1)
        printf("%c",lable);
    else if(1<n<=1000)
    {
       for(i=2;(num+2*(2*i-1))<=n;i++)
       {
            num+=2*(2*i-1);
       }
       leave=n-num;

       j=0;
       for(k=i-1;k>=1;k--)
       {
           for(p=0;p<j;p++)
           {
               printf("  ");
           }
           for(q=0;q<(2*k-1);q++)
           {
               if(q==(2*k-2))
                printf("%c",lable);
               else
                printf("%c ",lable);
           }
           printf("\n");
           j++;
       }

       for(k1=2;k1<i;k1++)
       {
           for(p1=j-1;p1>1;p1--)
           {
               printf("  ");
           }
           for(q1=0;q1<(2*k1-1);q1++)
           {
               if(q1==(2*k1-2))
                printf("%c",lable);
               else
                printf("%c ",lable);
           }
           printf("\n");
           j--;
       }
    }
    else
        printf("Error!");

    printf("%d\n",leave);
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k,i,p,q,k1,p1,q1,j,n,num=1,leave;
    char lable;
    scanf("%d %c",&n,&lable);
    if(n==1)
    {
        printf("%c\n",lable);
        printf("0");
    }
    else if(1<n<=1000)
    {
       for(i=2;(num+2*(2*i-1))<=n;i++)
       {
            num+=2*(2*i-1);
       }
       leave=n-num;

       j=0;
       for(k=i-1;k>=1;k--)
       {
           for(p=0;p<j;p++)
           {
               printf(" ");
           }
           for(q=0;q<(2*k-1);q++)
           {
                printf("%c",lable);
           }
           printf("\n");
           j++;
       }

       for(k1=2;k1<i;k1++)
       {
           for(p1=j-1;p1>1;p1--)
           {
               printf(" ");
           }
           for(q1=0;q1<(2*k1-1);q1++)
           {
                printf("%c",lable);
           }
           printf("\n");
           j--;
       }
       printf("%d\n",leave);
    }
    else
        printf("Error!");
    return 0;
}
