#include <stdio.h>
#include <stdlib.h>
/*
Ҫ����������C���Ե�qsort����
�±����й���������ѽ�ʱ�Ե�һ�ִ�ͳʳƷ����ͬ��������಻ͬ��ζ���±����ָ������������±��Ŀ���������ۼۡ��Լ��г�����������������������Ի�õ���������Ƕ��١�

ע�⣺����ʱ����ȡ��һ���ֿ�档���������������������ģ�����������3���±����������ֱ�Ϊ18��15��10��֣����ۼ۷ֱ�Ϊ75��72��45��Ԫ������г������������ֻ��20��֣���ô��������������Ӧ��������ȫ��15��ֵ�2���±����Լ�5��ֵ�3���±������ 72 + 45/2 = 94.5����Ԫ����

�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��ʾ�±������������Լ�������500�������Ϊ��λ����������D��ʾ�г���������������һ�и���N��������ʾÿ���±��Ŀ�����������Ϊ��λ�������һ�и���N��������ʾÿ���±������ۼۣ�����ԪΪ��λ�������ּ��Կո�ָ���

�����ʽ��

��ÿ�������������һ�������������棬����ԪΪ��λ����ȷ��С�����2λ��
����������

3 20
18 15 10
75 72 45

���������

94.50

*/
struct Price
{
    int type;
    double price;
}p[1000],*aa,*bb;
int cmp(const void *a,const void *b)
{
     aa=(struct Price *)a;
     bb=(struct Price *)b;
     return(((aa->price)<(bb->price))?1:-1);
}

int main()
{
    int n,d,i;
    double sal=0,stock[1000],income[1000],D=0;
    scanf("%d%d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%lf",&stock[i]);
        D+=stock[i];
    }
    for(i=0;i<n;i++)
    {
        scanf("%lf",&income[i]);
        sal+=income[i];
    }
    if(d>=D)
        printf("%0.2f",sal);
    else
    {
    for(i=0;i<n;i++)
    {
        p[i].type=i;
        p[i].price=income[i]/stock[i];
    }
    qsort(p,n,sizeof(p[0]),cmp);
    double sales=0,most=0;
    for(i=0;i<n;i++)
    {
        //printf("%d %f\n",sales,most);
        if(sales<d)
        {
            double k=sales;
            sales+=stock[p[i].type];
            if(sales<=d)
                most=most+p[i].price*stock[p[i].type];
            else
                most=most+(d-k)*p[i].price;
        }
    }

    printf("%0.2f",most);
    }
   //for(i=0;i<n;i++)
         //printf("%d %f\n",p[i].type,p[i].price);
    return 0;
}
