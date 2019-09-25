/*
火星人是以13进制计数的：

    地球人的0被火星人称为tret。
    地球人数字1到12的火星文分别为：jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec。
    火星人将进位以后的12个高位数字分别称为：tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou。

例如地球人的数字“29”翻译成火星文就是“hel mar”；而火星文“elo nov”对应地球数字“115”。为了方便交流，请你编写程序实现地球和火星数字之间的互译。

输入格式：

输入第一行给出一个正整数N（<100），随后N行，每行给出一个[0, 169)区间内的数字 —— 或者是地球文，或者是火星文。

输出格式：

对应输入的每一行，在一行中输出翻译后的另一种语言的数字。
输入样例：

4
29
5
elo nov
tam

输出样例：

hel mar
may
115
13

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char *s1;
    char *s2;
}Mars[12];
int check(char a[])
{
    if(a[0]=='0')
        printf("tret\n");
    else if(!strcmp(a,"tret"))
        printf("0\n");
    else
        return 0;
    return 1;

}
int transform_single(char p[])
{
    int i;
    for(i=0;i<12;i++)
        if(!strcmp(p,Mars[i].s1))
            return i;
    return -1;
}
int transform_tens(char p[])
{
    int i;
    for(i=0;i<12;i++)
        if(!strcmp(p,Mars[i].s2))
            return i;
    return -1;
}
int main()
{
    Mars[0].s1="jan";  Mars[0].s2="tam";
    Mars[1].s1="feb";  Mars[1].s2="hel";
    Mars[2].s1="mar";  Mars[2].s2="maa";
    Mars[3].s1="apr";  Mars[3].s2="huh";
    Mars[4].s1="may";  Mars[4].s2="tou";
    Mars[5].s1="jun";  Mars[5].s2="kes";
    Mars[6].s1="jly";  Mars[6].s2="hei";
    Mars[7].s1="aug";  Mars[7].s2="elo";
    Mars[8].s1="sep";  Mars[8].s2="syy";
    Mars[9].s1="oct";  Mars[9].s2="lok";
    Mars[10].s1="nov";  Mars[10].s2="mer";
    Mars[11].s1="dec";  Mars[11].s2="jou";
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char a[7];
        gets(a);
        if(!check(a))
        {
            if(atoi(a))
            {
                int b,c;
                b=atoi(a)%13;
                c=(atoi(a)%169)/13;
                if(c!=0&&b!=0)
                    printf("%s %s\n",Mars[c-1].s2,Mars[b-1].s1);
                else if(b!=0)
                    puts(Mars[b-1].s1);//printf("%s\n" Mars[b-1].s1);
                else
                    puts(Mars[c-1].s2);//printf("%s\n" Mars[c-1].s2);
            }
            else
            {
                char b[4],c[4];
                strncpy(b,a,3);
                b[3]='\0';
                if(transform_single(b)!=-1)
                    printf("%d\n",transform_single(b)+1);
                else
                {
                    if(strlen(a)>4)
                    {
                        strncpy(c,a+4,3);
                        c[3]='\0';
                        printf("%d\n",(transform_tens(b)+1)*13+transform_single(c)+1);
                    }
                    else
                        printf("%d\n",(transform_tens(b)+1)*13);
                }
            }
        }
    }
    return 0;
}
/*
设这两个字符串为str1，str2，
若str1==str2，则返回零；
若str1<str2，则返回负数；
若str1>str2，则返回正数。*/
