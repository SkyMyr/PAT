/*


�ļ�����ʱ���κ���Ҫ������Ը�����N����K�ŵĶ�������Ŷӹ������£�

    ÿ������ΪN/K������ȡ���������������ȫ��վ�����һ�ţ�
    ���������˵ĸ��Ӷ�����ǰ���κ��˰���
    ÿ���������վ�м䣨�м�λ��Ϊm/2+1������mΪ������������������ȡ������
    ÿ�����������м���Ϊ�ᣬ����߷��������Һ��������վ���м��˵����ࣨ����5�����Ϊ190��188��186��175��170�������Ϊ175��188��190��186��170�������������������ߣ��������������м��˵��ұߣ���
    �����������ͬ�������ֵ��ֵ����������С����ﱣ֤��������

�ָ���һ�������ˣ����д����������ǵĶ��Ρ�

�����ʽ��

ÿ���������1������������ÿ������������1�и�������������N��<=10000������������K��<=10���������������N�У�ÿ�и���һ���˵����֣��������ո񡢳��Ȳ�����8��Ӣ����ĸ������ߣ�[30, 300]�����ڵ���������

�����ʽ��

������յĶ��Ρ���K������������Կո�ָ�����ĩ�����ж���ո�ע�⣺��������������ߣ����ŵ���������Ϸ���ǰ��������·���
����������

10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

���������

Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct person
{
    char name[9];   //���ֳ��Ȳ�С�ڰ˸�  ���洢�˸����ȵ�����Ҫ�Ÿ����� ���һ����\n  �ӣ�
    int high;
}p[10000],*aa,*bb;

int cmp(const void *a,const void *b)
{
    aa=(struct person *)a;
    bb=(struct person *)b;
    if(aa->high==bb->high)
        return strcmp((aa->name),(bb->name));//int a1,a2;return a1>a2ֻ�᷵��0��1������0ʱ��ʾa1������a2,1��ʾa1����a2,��strcmp(s1,s2)�᷵��-1��0��1
    return (((aa->high)<(bb->high))?1:-1);
}
void prin(int i,int j,int num)
{
    int k,middel=num/2,order[num];
    order[middel]=i;
    for(k=1;;k++)
    {
        if(i==j)
            break;
        order[middel-k]=++i;
        if(i==j)
            break;
        order[middel+k]=++i;
    }
    for(k=0;k<num-1;k++)
    {
        printf("%s ",p[order[k]].name);
    }
    printf("%s\n",p[order[num-1]].name);
}
int main()
{
    int i,n,k;
    scanf("%d%d",&n,&k);
    int row=n/k;
    for(i=0;i<n;i++)
    {
        scanf("%s%d",p[i].name,&p[i].high);
    }
    qsort(p,n,sizeof(p[0]),cmp);
    int row1=row+n%k;
    prin(0,row1-1,row1);
    if(n>=k)
    for(i=1;i<k;i++)
    {
        prin(row1+row*(i-1),row1+row*i-1,row);
    }
    /*for(i=0;i<n;i++)
         printf("%s %d\n",p[i].name,p[i].high);
    printf("Hello world!\n");*/
    return 0;
}
