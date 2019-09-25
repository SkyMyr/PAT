/*


本题的目标很简单，就是判断一个给定的正整数是否素数。

输入格式：

输入在第一行给出一个正整数N（<=10），随后N行，每行给出一个小于231的需要判断的正整数。

输出格式：

对每个需要判断的正整数，如果它是素数，则在一行中输出“Yes”，否则输出“No”。
输入样例：

2
11
111

输出样例：

Yes
No

*/
//http://blog.csdn.net/huang_miao_xin/article/details/51331710  素数判断的三种方法
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
void judge(long a)
{
    long i;
    if(a==1)
        printf("No\n");
    else if(a>1)
    {
        for(i=2;i<=sqrt(a);i++) //遍历2到根号N即可
        {
            if(a%i==0)
            {
                printf("No\n");
                return;
            }
        }
        printf("Yes\n");
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        long a;
        scanf("%ld",&a);
        judge(a);
    }
    return 0;
}
