#include <stdio.h>
#include <stdlib.h>
struct node  //��û���ظ�������
{
    int key;
    int next;
}a[100000];
struct del //��ɾ��������
{
    int id;
    int key;
}b[100000];
int flag[100000]={0};//��־�ظ����
int m=0;       //�ظ��ĸ���
void delet(int pre,int next)
{
  int key=0;
  if(next==-1)      //��β
    return ;
  if(flag[abs(a[next].key)]==0)//����û���ظ�ʱ
  {
    flag[abs(a[next].key)]=1;//�����
    delet(next,a[next].next);//������һ�������ͷβ

  }
  else//�ظ�ʱ
  {
    a[pre].next=a[next].next;//��ǰ��ͷ������һ����β��
    b[m].id=next;//��¼ɾ���ĵ�ַ
    b[m].key=a[next].key;//��¼ɾ���ļ�ֵ
    m++;
    delet(pre,a[next].next);//���뵱ǰ�����ͷ������һ����β��
  }
}
void print1(int n)
{

  while(a[n].next!=-1)
  {
    printf("%05d %d %05d\n",n,a[n].key,a[n].next);
    n=a[n].next;
  }
  printf("%05d %d %d\n",n,a[n].key,a[n].next);

}
void print2()
{
  if(m>=1)
  {
    int i;
    for(i=0;i<m-1;i++)
    {
      printf("%05d %d %05d\n",b[i].id,b[i].key,b[i+1].id);
    }
    printf("%05d %d -1\n",b[m-1].id,b[m-1].key);
  }

}
int main()
{
    int n,start,tstart,key,tnext;
    scanf("%d%d",&start,&n);
    while(n--)
    {
        scanf("%d%d%d",&tstart,&key,&tnext);
        a[tstart].key=key;
        a[tstart].next=tnext;
    }
    flag[abs(a[start].key)]=1;
    delet(start,a[start].next);
    print1(start);
    print2();
    return 0;
}
