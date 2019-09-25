#include <stdio.h>
#include <stdlib.h>
int judge(char a,char b)
{
    if(a==b)
        return 3;
    else if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C'))
        return 1;
    else
        return 2;
}
struct person
{
    int win,fail,draw,C,J,B;
}p1,p2;
int main()
{
    int i,n;
    char m1,m2;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        char a[4];
        gets(a);
        if(judge(a[0],a[2])==1)
        {
            p1.win++;
            if(a[0]=='C')
                p1.C++;
            else if(a[0]=='B')
                p1.B++;
            else
                p1.J++;
            p2.fail++;
        }
        else if(judge(a[0],a[2])==2)
        {
            p2.win++;
            if(a[2]=='C')
                p2.C++;
            else if(a[2]=='B')
                p2.B++;
            else
                p2.J++;
            p1.fail++;
        }
        else
        {
            p1.draw++;
            p2.draw++;
        }
    }
    printf("%d %d %d\n",p1.win,p1.draw,p1.fail);
    printf("%d %d %d\n",p2.win,p2.draw,p2.fail);
    if(p1.C>=p1.J&&p1.C>p1.B)
        m1='C';
    else if(p1.J>p1.C&&p1.J>p1.B)
        m1='J';
    else
        m1='B';
    if(p2.C>=p2.J&&p2.C>p2.B)
        m2='C';
    else if(p2.J>p2.C&&p2.J>p2.B)
        m2='J';
    else
        m2='B';
    printf("%c %c",m1,m2);
    return 0;
}
/*
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。
输入样例：

10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J

输出样例：

5 3 2
2 3 5
B B

*/
