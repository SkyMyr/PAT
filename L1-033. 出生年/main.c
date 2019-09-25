#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count,y,n,year;
    scanf("%d%d",&y,&n);
    for(year=y;;year++)
    {
        int a=year/1000,b=(year%1000)/100,c=(year%100)/10,d=year%10;
        //printf("%d %d %d %d\n",a,b,c,d);
        if(a==b&&b==c&&c==d)
        {
            continue;
            /*count=1;
            if(count==n)
            {
                printf("%d %04d",year-y,year);
                break;
            }*/
        }
        else if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d)
        {
            count=4;
            if(count==n)
            {
                printf("%d %04d",year-y,year);
                break;
            }
        }
        else if((a==b&&b==c&&c!=d)||(a==b&&b==d&&c!=d)||(a!=b&&a==c&&c==d)||(a!=b&&b==c&&c==d)||(a==b&&c==d&&a!=c)||(a==c&&b==d&&a!=b)||(a==d&&c==b&&a!=b))
        {
            count=2;
            if(count==n)
            {
                printf("%d %04d",year-y,year);
                break;
            }
        }
        else
        {
            count=3;
            if(count==n)
            {
                printf("%d %04d",year-y,year);
                break;
            }
        }

    }
        return 0;
}

/*

有新浪微博中一奇葩贴：“我出生于1988年，直到25岁才遇到4个数字都不相同的年份。”也就是说，直到2013年才达到“4个数字都不相同”的要求。本题请你根据要求，自动填充“我出生于y年，直到x岁才遇到n个数字都不相同的年份”这句话。

输入格式：

输入在一行中给出出生年份y和目标年份中不同数字的个数n，其中y在[1, 3000]之间，n可以是2、或3、或4。注意不足4位的年份要在前面补零，例如公元1年被认为是0001年，有2个不同的数字0和1。

输出格式：

根据输入，输出x和能达到要求的年份。数字间以1个空格分隔，行首尾不得有多余空格。年份要按4位输出。注意：所谓“n个数字都不相同”是指不同的数字正好是n个。如“2013”被视为满足“4位数字都不同”的条件，但不被视为满足2位或3位数字不同的条件。
输入样例1：

1988 4

输出样例1：

25 2013

输入样例2：

1 2

输出样例2：

0 0001

*/
