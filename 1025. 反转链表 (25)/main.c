/*


����һ������K�Լ�һ��������L�����д����L��ÿK����㷴ת�����磺����LΪ1��2��3��4��5��6��KΪ3�������Ӧ��Ϊ3��2��1��6��5��4�����KΪ4�������Ӧ��Ϊ4��3��2��1��5��6������󲻵�K��Ԫ�ز���ת��

�����ʽ��

ÿ���������1������������ÿ������������1�и�����1�����ĵ�ַ������ܸ���������N(<= 105)���Լ�������K(<=N)����Ҫ��ת���������ĸ��������ĵ�ַ��5λ�Ǹ�������NULL��ַ��-1��ʾ��

��������N�У�ÿ�и�ʽΪ��

Address Data Next

����Address�ǽ���ַ��Data�Ǹý�㱣����������ݣ�Next����һ���ĵ�ַ��

�����ʽ��

��ÿ������������˳�������ת�����������ÿ�����ռһ�У���ʽ��������ͬ��
����������

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

���������

00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{

    int value;
    int next;
}Node;
int i,n,k;//pre[100001];
int head,q,p=100000,count=0;
Node a[100001];
void reverse(int A)
{
    int m=a[A].next,r=A;
    //printf("%d %d\n",A,a[A].next);
    int s[100001],top=-1;  /*��ʼ��ջ*/
    while(top<k-1)      /*�������н������ѹջ*/
    {
        top++;
        s[top]=m;
        //printf("%d\n",s[top]);
        m=a[m].next;
        //printf("%d %d\n",m,top);
        if(m==-1)
            break;
    }
    if(top==k-1)
    {
        while(top!=-1) /*��ջ��Ԫ�����γ�ջ*/
        {
            a[r].next=s[top];
            top--;
            r=a[r].next;
            a[r].next=s[top];
            //printf("%d %d %d\n",r,a[r].value,a[r].next);
        }
        a[r].next=m;//printf("%05d %d %05d\n",r,a[r].value,a[r].next);
    }
}

int main()
{
    scanf("%d%d%d",&head,&n,&k);
    //printf("%d %d\n",head,n);
    for(i=0;i<n;i++)
    {
        int self,val,net;
        scanf("%d%d%d",&self,&val,&net);
        a[self].next=net;
        a[self].value=val;
        //printf("%d%d%d",self,a[self].value,a[self].next);
    }
    a[p].next=head;
    /*while(p!=-1)
    {
        if(a[p].next!=-1)
            pre[a[p].next]=p;
        p = a[p].next;
    }*/
    for(q=p;q!=-1;q=a[q].next)
    {
        if(count==0)
            {reverse(q);}
        else if(count%k==0)
            {reverse(q);}
        count++;
    }
    q=a[100000].next;
    while(q!=-1)
    {
        if(a[q].next!=-1)
            printf("%05d %d %05d\n",q,a[q].value,a[q].next);
        else
            printf("%05d %d %d\n",q,a[q].value,a[q].next);
        q=a[q].next;
    }
    //printf("Hello world!\n");
    return 0;
}
