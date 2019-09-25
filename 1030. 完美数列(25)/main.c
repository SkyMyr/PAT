/*


给定一个正整数数列，和正整数p，设这个数列中的最大值是M，最小值是m，如果M <= m * p，则称这个数列是完美数列。

现在给定参数p和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数N和p，其中N（<= 105）是输入的正整数的个数，p（<= 109）是给定的参数。第二行给出N个正整数，每个数不超过109。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。
输入样例：

10 8
2 3 20 4 5 1 6 7 8 9

输出样例：

8

*/
#include <stdio.h>
#include <stdlib.h>
int i,j,n;
double p,a[100010];
int cmp(const void *a,const void *b)
{
    return *(double *)a - *(double *)b;
}
int main()
{
    double M,m;
    scanf("%d%lf",&n,&p);

    for(i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    qsort(a,n,sizeof(double),cmp);
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            m=a[j];
            M=a[j+n-i-1];
            if(M<=m*p)
                {printf("%d",n-i);return 0;}
        }

    }
    return 0;
}
    /*int first,last,max = 0;
    for(first = 0, last = 0; last < n; first++)
    {
        while(last < n && a[last] <= 1L * a[first] * p)
            last++;
        if(max < last - first)
            max = last - first;
    }
    printf("%d", max);*/

    //printf("%d %d",M,m);
