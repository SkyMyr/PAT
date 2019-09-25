#include <stdio.h>
#include <stdlib.h>
struct node  //放没有重复的链表
{
    int key;
    int next;
}a[100000];
struct del //放删除的链表
{
    int id;
    int key;
}b[100000];
int flag[100000]={0};//标志重复与否
int m=0;       //重复的个数
void delet(int pre,int next)
{
  int key=0;
  if(next==-1)      //链尾
    return ;
  if(flag[abs(a[next].key)]==0)//链表没有重复时
  {
    flag[abs(a[next].key)]=1;//做标记
    delet(next,a[next].next);//传入下一条链表的头尾

  }
  else//重复时
  {
    a[pre].next=a[next].next;//当前的头等于下一个的尾巴
    b[m].id=next;//记录删除的地址
    b[m].key=a[next].key;//记录删除的键值
    m++;
    delet(pre,a[next].next);//传入当前链表的头，和下一条的尾巴
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
