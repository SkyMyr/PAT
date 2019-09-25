#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。
输入样例：

123456789050987654321 7

输出样例：

17636684150141093474 3
*/

int main()
{
    char a[1001];
    int b,i,len,yu=0,flag=0;
    scanf("%s%d",a,&b);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        yu=a[i]-'0'+yu*10;
        if(yu>=b)
        {
            printf("%d",yu/b);
            flag=1;
        }
        else if(flag)
        {
            printf("0");
        }
        yu=yu%b;
    }
    if(flag==0)
        printf("0");
    printf(" %d",yu);
    return 0;
}
