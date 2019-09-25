/*


大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；
第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。
题目输入保证每个测试存在唯一解。
输入样例：

3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

输出样例：

THU 14:04


*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int mm;
char day,hh,a[60],b[60],c[60],d[60];
void search1()
{
    int i,p,count=0;
    for(i=0;i<strlen(a)&&i<strlen(b);i++)
    {
            if(count==0&&'A'<=a[i]&&a[i]<='G'&&a[i]==b[i])
            {
                day=a[i];
                count++;
                for(p=i+1;p<strlen(a)&&p<strlen(b);p++)
                {

                        if(count==1&&(('A'<=a[p]&&a[p]<='N')||('0'<=a[p]&&a[p]<='9'))&&a[p]==b[p])
                        {
                            hh=a[p];
                            //printf("p=%d,q=%dhh=%c\n",p,q,hh);
                            return ;
                        }

                }
            }
    }
}
void search2()
{
    int i;
    for(i=0;i<strlen(c)&&i<strlen(d);i++)
    {
            if(c[i]==d[i])//65<=c[i]&&c[i]<=90||97<=c[i]&&c[i]<=122 &&
            {
                if((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
                {
                    mm=i;
                    printf("%02d",mm);
                    return ;
                }
                //printf("---c%d=%c d%d=%c---",i,c[i],j,d[j]);
            }
    }
}
void DAY(char week)
{
    switch(week)
    {
        case'A':printf("MON ");break;
        case'B':printf("TUE ");break;
        case'C':printf("WED ");break;
        case'D':printf("THU ");break;
        case'E':printf("FRI ");break;
        case'F':printf("SAT ");break;
        case'G':printf("SUN ");break;
        default:printf("error!\n");break;
    }
}
void HH(char hour)
{
    int count=10;
    char i;
    if(hour>='0'&&hour<='9')
    {
        printf("0%c:",hour);
    }
    else
    {
        for(i='A';i<='N';i++)
        {
            if(hour==i)
            {
                printf("%d:",count);
                return;
            }
            count++;
        }
    }
}
int main()
{
    scanf("%s%s%s%s",a,b,c,d);
    search1();
    DAY(day);
    HH(hh);
    search2();
    return 0;
}
