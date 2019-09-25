
/*
看我没骗你吧 —— 这是一道你可以在10秒内完成的题：给定两个绝对值不超过100的整数A和B，输出A乘以B的值。

输入格式：

输入在第一行给出两个整数A和B（-100 <= A, B, <= 100），数字间以空格分隔。

输出格式：

在一行中输出A乘以B的值。
输入样例：

-8 13

输出样例：

-104
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,sum=1;
    scanf("%d%d",&a,&b);
    if(-100<=a<=100&&-100<=b<=100)
    {
        sum=a*b;
    }
    printf("%d\n",sum);
    return 0;
}
