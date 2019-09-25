/*


请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

输入格式：

输入在一行中给出一个长度不超过1000的字符串。字符串由ASCII码表中任意可见字符及空格组成，至少包含1个英文字母，以回车结束（回车不算在内）。

输出格式：

在一行中输出出现频率最高的那个英文字母及其出现次数，其间以空格分隔。如果有并列，则输出按字母序最小的那个字母。统计时不区分大小写，输出小写字母。
输入样例：

This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........

输出样例：

e 7

*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char a[1010];
struct data
{
    int n;
    char Letter;
}b[26],*aa,*bb;
int comp(const void *a,const void *b)
{
    aa=(struct data *)a;
    bb=(struct data *)b;
    if(aa->n==bb->n)
        return aa->Letter-bb->Letter;
    return bb->n-aa->n;
}
int cmp(const void *a,const void *b)
{
    return *(char *)a - *(char *)b;
}
int main()
{
    int i,p=0;
    gets(a);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>=65&&a[i]<=90)
            a[i]=a[i]+32;
    }
    qsort(a,strlen(a),sizeof(a[0]),cmp);
    for(i=0;i<26;i++)
    {
        b[i].n=0;
    }
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>=97&&a[i]<=122)
        {
            int k=1;
            for(;i<strlen(a);i++)
            {
                if(a[i+1]==a[i])
                    k++;
                else
                {
                    b[p].Letter=a[i];
                    b[p].n=k;
                    p++;
                    break;
                }
            }
        }
    }
    qsort(b,p,sizeof(b[0]),comp);
    printf("%c %d",b[0].Letter,b[0].n);
    return 0;
}
