#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i,j,k=0,count=0,max=0;
    double p[1000],q[1000];
    char a[1000],b[1000];
    gets(a);
    gets(b);
    for(i=0;i<=strlen(a);i++)
    {
        if(a[i]==' ' || a[i]=='\0')
        {
            char tp[8];
            strncpy(tp,a+k,i-k);
            p[count]=atof(tp);
            //printf("%d %f\n",i,p[count]);
            count++;
            k=i+1;
        }
    }
    int length_p=count;
    k=0;count=0;
    for(i=0;i<=strlen(b);i++)
    {
        if(b[i]==' ' || b[i]=='\0')
        {
            char tmp[8];
            strncpy(tmp,b+k,i-k);
            q[count]=atof(tmp);
            //printf("%d %f\n",i,q[count]);
            count++;
            k=i+1;
        }
    }
    int length_q=count;
    //printf("%d %d\n",length_p,length_q);
    for(i=0;i<length_q;i+=4)
    {
        count=0;
        for(j=0;j<length_p;j+=2)
        {
            if(p[j]>=q[i]&&p[j]<=q[i+2]&&p[j+1]>=q[i+1]&&p[j+1]<=q[i+3])
            {
                count++;
            }
        }
        max=(max>=count)?max:count;
    }
    printf("%d",max);
    return 0;
}
/*
�������ɸ������������ɸ��������򣬴���һ�������ĵ���������ľ��������������������
����

��һ���������ɸ�������꣬x
�� y �ɶԳ��֡� �ڶ����������ɸ���������x1,y1,x2,y2

������֡�
���

���һ�У�������Ŀ��Ҫ��Ĵ�
��������
Copy

1 1 2 2 3 3 4 4
0 0 5 5

�������
Copy

4

��ʾ

�����Ϊʵ�����뽫����������ɢ������*/
