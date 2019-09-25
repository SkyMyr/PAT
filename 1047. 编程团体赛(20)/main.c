/*
编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

输入格式：

输入第一行给出一个正整数N（<=10000），即所有参赛队员总数。随后N行，每行给出一位队员的成绩，格式为：“队伍编号-队员编号 成绩”，其中“队伍编号”为1到1000的正整数，“队员编号”为1到10的正整数，“成绩”为0到100的整数。

输出格式：

在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。
输入样例：

6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61

输出样例：

11 176

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    int team;
    char a[10];
    int score;
}c[10010];
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%s%d",&c[i].team,c[i].a,&c[i].score);
    }
    int a[10010],most=0;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        a[c[i].team] += c[i].score;
    }
    for(i=1;i<=1000;i++)
    {
        if(most<a[i])
        {
            most=a[i];
            j=i;
        }
    }
    printf("%d %d",j,most);
    //printf("Hello world!\n");
    return 0;
}
