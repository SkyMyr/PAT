/*


��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�
����������

5 27

���������

11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103


*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int judge(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n,m,i,k=0,a[10000];
    scanf("%d%d",&m,&n);
    for(i=2;k<n;i++)
    {
        if(judge(i))
        {
            a[k]=i;
            k++;
        }
    }
    int count=0;
    for(i=m-1;i<n;i++)
    {
        if(count%10==9||count==n-m)     //�ر�ע����ĩ�����пո�ֻ��ʮ��ĩ  ���һ��ĩҲ������
            printf("%d",a[i]);
        else
            printf("%d ",a[i]);
        count++;
        if(count%10==0)
            printf("\n");
    }
    return 0;
}
