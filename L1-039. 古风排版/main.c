/*


中国的古人写文字，是从右向左竖向排版的。本题就请你编写程序，把一段文字按古风排版。

输入格式：

输入在第一行给出一个正整数N（<100），是每一列的字符数。第二行给出一个长度不超过1000的非空字符串，以回车结束。

输出格式：

按古风格式排版给定的字符串，每列N个字符（除了最后一列可能不足N个）
输入样例：

4
This is a test case

输出样例：

asa T
st ih
e tsi
 ce s

*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//需要把字符串数组开到1100 否则会段错误
int main()
{
    int n;
    char s[1100];
    scanf("%d",&n);
    getchar();
    gets(s);
    int length=strlen(s),column;
    if(length%n==0)
    {
        column=length/n;
    }
    else
    {
        int i,r=length;

        column=length/n+1;
        for(i=length%n;i<n;i++)
        {
            s[r]=' ';
            r++;
        }
    }
    char antiquity[n][column];
    int i,j,k=0;
    for(i=column-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            antiquity[j][i]=s[k];
            k++;
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<column;j++)
            printf("%c",antiquity[i][j]);
        printf("\n");
    }

    return 0;
}

//直接补不用额外开字符串数组空间
int main()
{
    int n;
    char s[1000];
    scanf("%d",&n);
    getchar();
    gets(s);
    //printf("%c\n",s[16]);
    int length=strlen(s),column;
    //printf("%d\n",length);
    if(length%n==0)
    {
        column=length/n;
    }
    else
    {
        column=length/n+1;
    }
    char antiquity[n][column];
    int i,j,k=0;
    for(i=column-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(k<length)
            {
                antiquity[j][i]=s[k];
                k++;
            }
            else
                antiquity[j][i]=' ';
            //printf("%c\n",antiquity[j][i]);
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<column;j++)
            printf("%c",antiquity[i][j]);
        printf("\n");
    }

    return 0;
}
