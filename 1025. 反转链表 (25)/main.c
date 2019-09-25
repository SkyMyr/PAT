/*


给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1→2→3→4→5→6，K为3，则输出应该为3→2→1→6→5→4；如果K为4，则输出应该为4→3→2→1→5→6，即最后不到K个元素不反转。

输入格式：

每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N(<= 105)、以及正整数K(<=N)，即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。

接下来有N行，每行格式为：

Address Data Next

其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
输入样例：

00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

输出样例：

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
    int s[100001],top=-1;  /*初始化栈*/
    while(top<k-1)      /*将链表中结点依次压栈*/
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
        while(top!=-1) /*将栈中元素依次出栈*/
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
