/*
ר��ͨ�����������о����ݷ��֣���ѵ�������߲���ѭ��һ����ʽ����Ů������ߣ���1.09=���з�����ߣ���
������ϣ���������߲����ǣ�֡�ӵ�������ǣ��������г�Ĳ�ȡ�

���������д������Ϊ����һλ�û�������/�������µ������ߡ�

�����ʽ��

�����һ�и���������N��<=10����Ϊǰ����ѯ���û��������N�У�ÿ�а��ա��Ա� ��ߡ��ĸ�ʽ����ǰ����ѯ���û����Ա����ߣ�
���С��Ա�Ϊ��F����ʾŮ�ԡ���M����ʾ���ԣ�����ߡ�Ϊ���� [1.0, 3.0] ֮���ʵ����

�����ʽ��

��ÿһ����ѯ����һ����Ϊ���û�����������µ������ߣ�����С�����2λ��
����������

2
M 1.75
F 1.8

���������

1.61
1.96


#include <stdio.h>
#include <stdlib.h>
struct person
{
    char sex;
    double high;
}p[10];
int main()
{
    int i,n;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        scanf("%c",&p[i].sex);
        getchar();
        scanf("%lf",&p[i].high);
        getchar();//scanf���Իس����д��������Կո���Ϊ�ַ�����Ľ����� ��getchar()��Կո���д����Իس���Ϊ���������
    }
    for(i=0;i<n;i++)
    {
        if(p[i].sex =='F')
            printf("%.2lf\n",p[i].high*1.09);
        else
            printf("%.2lf\n",p[i].high/1.09);
    }
    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    getchar();
      char a;
      double high;
      scanf("%c %lf",&a,&high);
      if(a=='M')
      {
        printf("%.2lf",(high/1.09));
      }
      else
        printf("%.2lf",(high*1.09));
    }
    return 0;
}

