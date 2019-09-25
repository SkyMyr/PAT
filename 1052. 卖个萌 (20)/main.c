#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char hand[100],eye[100],mouth[100];
int main()
{
    gets(hand);
    gets(eye);
    gets(mouth);
    int i,j=0,k,h[100],e[100],m[100];
    for(i=0;i<strlen(hand);i++)
    {
         if(hand[i]=='[')
         {
            j++;
            h[j]=i;
         }
    }
    h[0]=j;
    //printf("%d\n",h[0]);
    j=0;
    for(i=0;i<strlen(eye);i++)
    {
         if(eye[i]=='[')
         {
            j++;
            e[j]=i;
         }
    }
    e[0]=j;
    //printf("%d\n",e[0]);
    j=0;
    for(i=0;i<strlen(mouth);i++)
    {
         if(mouth[i]=='[')
         {
            j++;
            m[j]=i;
         }
    }
    m[0]=j;
    //printf("%d\n",m[0]);
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        int a[10];
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[j]);
        }
        if(a[0]>h[0]||a[1]>e[0]||a[2]>m[0]||a[3]>e[0]||a[4]>h[0]||(a[0]<1) || (a[1]<1) || (a[2]<1) || (a[3]<1) || (a[4]<1))//注意上界和下界都得考虑
        {
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        char b[100];
        int a1=h[a[0]]+1;
        int a2=e[a[1]]+1;
        int a3=m[a[2]]+1;
        int a4=e[a[3]]+1;
        int a5=h[a[4]]+1;
        for(j=0;hand[a1]!=']';j++)
            b[j]=hand[a1++];
        b[j]='(';j++;
        for(;eye[a2]!=']';j++)
            b[j]=eye[a2++];
        for(;mouth[a3]!=']';j++)
            b[j]=mouth[a3++];
        for(;eye[a4]!=']';j++)
            b[j]=eye[a4++];
        b[j]=')';j++;
        for(;hand[a5]!=']';j++)
            b[j]=hand[a5++];
        b[j]='\0';
        printf("%s\n",b);
    }
    return 0;
}

/*
萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

[左手]([左眼][口][右眼])[右手]

现给出可选用的符号集合，请你按用户的要求输出表情。

输入格式：

输入首先在前三行顺序对应给出手、眼、口的可选符号集。每个符号括在一对方括号[]内。题目保证每个集合都至少有一个符号，并不超过10个符号；每个符号包含1到4个非空字符。

之后一行给出一个正整数K，为用户请求的个数。随后K行，每行给出一个用户的符号选择，顺序为左手、左眼、口、右眼、右手——这里只给出符号在相应集合中的序号（从1开始），数字间以空格分隔。

输出格式：

对每个用户请求，在一行中输出生成的表情。若用户选择的序号不存在，则输出“Are you kidding me? @\/@”。
输入样例：

[╮][╭][o][~\][/~]  [<][>]
 [╯][╰][^][-][=][>][<][@][⊙]
[Д][▽][_][ε][^]  ...
4
1 1 2 2 2
6 8 1 5 5
3 3 4 3 3
2 10 3 9 3

输出样例：

╮(╯▽╰)╭
<(@Д=)/~
o(^ε^)o
Are you kidding me? @\/@
*/
