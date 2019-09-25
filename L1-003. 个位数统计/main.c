/*
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出格式：

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。
输入样例：

100311

输出样例：

0:2
1:3
3:1
*/
/*有BUG版本
int main()
{
    int i,a[10]={0};
    long int n,m;
    scanf("%ld",&n);
    if(n==1)
        printf("1:1");
    else if(1<n<2147483647)
    {
        for(m=10;m<10*n;m=m*10)
        {
            long int k=(n%m)/(m/10);
            a[k]++;
        }
        for(i=0;i<10;i++)
        {
            if(a[i]!=0)
                printf("%d:%d\n",i,a[i]);
        }
    }
    else
        printf("Error");
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int a[10]={0};
    int i,k,len;
    char s[1001];
    scanf("%s",s);
    len=strlen(s);
    /*strlen(char *):检测的是'\0',strlen(char *)碰到'\0'就返回'\0'以前的字符数.
    如：
    char f[]="123456\01111";
    int b=strlen(f);//b=6,因为遇到了'\0'
    char h[4]={'f','0',0,'h'} ;//注：不能写成char h[4]="f0\0h";因为以""括起来的为字符串,
    它隐式的以'\0'结尾,而'\0'也占一个字节,所以应写为char h[5]="f0\0h"
    int c=strlen(h);//c=2,因为遇到了'\0'(注意'0'不等于'\0',而0等于'\0')*/
    for(i=0;i<len;i++)
    {
        k=s[i]-'0';
        a[k]++;
    }
    for(i=0;i<10;i++)
    {
        if(a[i]!=0)
            printf("%d:%d\n",i,a[i]);
    }
    return 0;
}
