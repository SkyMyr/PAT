/*


�����Ŀ��ܼ򵥣������ж�һ���������������Ƿ�������

�����ʽ��

�����ڵ�һ�и���һ��������N��<=10�������N�У�ÿ�и���һ��С��231����Ҫ�жϵ���������

�����ʽ��

��ÿ����Ҫ�жϵ��������������������������һ���������Yes�������������No����
����������

2
11
111

���������

Yes
No

*/
//http://blog.csdn.net/huang_miao_xin/article/details/51331710  �����жϵ����ַ���
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
        for(i=2;i<=sqrt(a);i++) //����2������N����
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
