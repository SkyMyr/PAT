/*


令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
输入样例：

5 27

输出样例：

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103


*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int judge(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m,i,k=0,a[10000];
    scanf("%d%d",&m,&n);
    for(i=2;k<n;i++)
    {
        if(judge(i))
        {
            a[k]=i;
            k++;
        }
    }
    int count=0;
    for(i=m-1;i<n;i++)
    {
        if(count%10==9||count==n-m)     //特别注意行末不能有空格不只是十个末  最后一行末也不能有
            printf("%d",a[i]);
        else
            printf("%d ",a[i]);
        count++;
        if(count%10==0)
            printf("\n");
    }
    return 0;
}
