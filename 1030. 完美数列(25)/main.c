/*


����һ�����������У���������p������������е����ֵ��M����Сֵ��m�����M <= m * p���������������������С�

���ڸ�������p��һЩ���������������ѡ�񾡿��ܶ��������һ���������С�

�����ʽ��

�����һ�и�������������N��p������N��<= 105����������������ĸ�����p��<= 109���Ǹ����Ĳ������ڶ��и���N����������ÿ����������109��

�����ʽ��

��һ�������������ѡ����ٸ����������������һ���������С�
����������

10 8
2 3 20 4 5 1 6 7 8 9

���������

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
