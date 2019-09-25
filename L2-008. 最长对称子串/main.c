/*


对给定的字符串，本题要求你输出最长对称子串的长度。例如，给定"Is PAT&TAP symmetric?"，最长对称子串为"s PAT&TAP s"，于是你应该输出11。

输入格式：

输入在一行中给出长度不超过1000的非空字符串。

输出格式：

在一行中输出最长对称子串的长度。
输入样例：

Is PAT&TAP symmetric?

输出样例：

11

*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[1010];
int main()
{
    gets(a);
    int tmp,i,j,max=0,len = strlen(a);

    for(i=0;i<len;i++)
    {
        tmp=1;
        for(j=1;j<len;j++)
        {
            if(i - j < 0 || i + j >= len || a[i - j] != a[i + j])
                break;
            tmp += 2;
        }
        max = tmp>max?tmp:max;

        tmp=0;
        for( j = 1; j < len; j++)
        {
            if(i - j + 1 < 0 || i + j >= len || a[i - j + 1] != a[i + j])
                break;
            tmp += 2;
        }
        max = tmp>max?tmp:max;
    }
    printf("%d",max);
    return 0;
}
