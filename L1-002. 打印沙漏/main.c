/*


本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式：

输入在一行给出1个正整数N（<=1000）和一个符号，中间以空格分隔。

输出格式：

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
输入样例：

19 *

输出样例：

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
