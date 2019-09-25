#include <stdio.h>
#include <stdlib.h>

typedef struct node{

    int value;
    int next;
}Node;
Node a[100001],b[100001];
int judge(int a[],int value,int n)
{
    int i;
    if(value<0)
        value=-value;
    for(i=0;i<n;i++)
    {
        if(value == a[i])
            return 0;
    }
    return 1;
}
int main()
{
    int i,n;
    int c[100001],pre[100001];
    int head;
    scanf("%d%d",&head,&n);
    //printf("%d %d\n",head,n);
    for(i=0;i<n;i++)
    {
        int self,val,net;
        scanf("%d%d%d",&self,&val,&net);
        a[self].next=net;
        a[self].value=val;
        //printf("%d%d%d",self,a[self].value,a[self].next);
    }
    int p=head;//原链表
    int q=100000;//重复链表
    int count =0;//未重复的个数
    //printf("%d %d\n",head,p);
    while(p!=-1)
    {
        //printf("head= %d p= %d\n",head,p);
        if(judge(c,a[p].value,count)==1)
        {
            if(a[p].value<0)
                c[count]=-a[p].value;
            else
                c[count]=a[p].value;
            count++;
        }
        else
        {
            b[q].next=p;
            b[p].value=a[p].value;
            q=p;
            //printf("%d %d\n",q,b[q].value);
            a[pre[p]].next=a[p].next;
        }
        if(a[p].next!=-1)
            pre[a[p].next]=p;
        p = a[p].next;
        //printf("head= %d p= %d\n",head,p);
    }
    b[q].next=-1;
    //printf("head= %d\n",head);
    while(head!=-1)
    {
        if(a[head].next!=-1)
            printf("%05d %d %05d\n",head,a[head].value,a[head].next);
        else
            printf("%05d %d %d\n",head,a[head].value,a[head].next);
        head=a[head].next;
    }
    q=b[100000].next;
    while(q!=-1)
    {
        if(b[q].next!=-1)
            printf("%05d %d %05d\n",q,b[q].value,b[q].next);
        else
            printf("%05d %d %d\n",q,b[q].value,b[q].next);
        q=b[q].next;
    }
    return 0;
}
/*00001 5
00001 7 00005
00005 8 00004
00003 9 00002
00002 -15 -1
00004 15 00003
*/
