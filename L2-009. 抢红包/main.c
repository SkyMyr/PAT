/*


û����û��������ɡ��� �������N����֮�以�෢�����������ļ�¼������ͳ��һ��������������ջ�

�����ʽ��

�����һ�и���һ��������N��<= 104���������뷢������������������������Щ�˴�1��N��š����N�У���i�и������Ϊi���˷�����ļ�¼����ʽ���£�

K N1 P1 ... NK PK

����K��0 <= K <= 20���Ƿ���ȥ�ĺ��������Ni������������˵ı�ţ�Pi��> 0�����������ĺ�����Է�Ϊ��λ����ע�⣺����ͬһ���˷����ĺ����ÿ�����ֻ����1�Σ������ظ�����

�����ʽ��

����������Ӹߵ��͵ĵݼ�˳�����ÿ���˵ı�ź��������ԪΪ��λ�����С�����2λ����ÿ���˵���Ϣռһ�У������ּ���1���ո�����������в��У�����������ĸ����ݼ������������в��У��򰴸��˱�ŵ��������
����������

10
3 2 22 10 58 8 125
5 1 345 3 211 5 233 7 13 8 101
1 7 8800
2 1 1000 2 1000
2 4 250 10 320
6 5 11 9 22 8 33 7 44 10 55 4 2
1 3 8800
2 1 23 2 123
1 8 250
4 2 121 4 516 7 112 9 10

���������

1 11.63
2 3.63
8 3.63
3 2.11
7 1.69
6 -1.67
9 -2.18
10 -3.26
5 -3.26
4 -12.32


*/
#include <stdio.h>
#include <stdlib.h>
struct  Grab_red
{
    int s,k,N[20];
    int P[20],money;

}p[10000],*aa,*bb;
int cmp(const void *a,const void *b)    //double�������Ƚ�
{
    aa=(struct Grab_red *)a;
    bb=(struct Grab_red *)b;
    if(aa->money==bb->money)
    {
        if(aa->k==bb->k)
            return aa->s-bb->s;
        return bb->k-aa->k;
    }
    return bb->money-aa->money;
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int a=0;
        p[i].s=i+1;
        scanf("%d",&p[i].k);
        for(j=0;j<p[i].k;j++)
        {
            scanf("%d %d",&p[i].N[j],&p[i].P[j]);
            a += p[i].P[j];
        }
        p[i].money = -a;
        //printf("%.2lf\n",p[i].money);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<p[i].k;j++)
        {
            p[p[i].N[j]-1].money += p[i].P[j];
        }
    }
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n;i++)
    {
        printf("%d %.2lf\n",p[i].s,(double)p[i].money/100);
    }

    /*
    for(i=0;i<n;i++)
    {
        printf("%d ",p[i].k);
        for(j=0;j<p[i].k;j++)
        {
            printf("%d %.0lf ",p[i].N[j],p[i].P[j]);//���ڳ����е��� scanf �� scanf_s ������Ϊ scanf �İ�ȫ�汾��ʱ����Ϊ double ���ͱ���ָ���ı�ʶ������ %f ������ %lf��
        }
        printf("\n");
    }
    printf("Hello world!\n");*/
    return 0;
}
