/*


给定一棵二叉树的中序遍历和前序遍历，请你先将树做个镜面反转，再输出反转后的层序遍历的序列。所谓镜面反转，是指将所有非叶结点的左右孩子对换。这里假设键值都是互不相等的正整数。

输入格式：

输入第一行给出一个正整数N（<=30），是二叉树中结点的个数。第二行给出其中序遍历序列。第三行给出其前序遍历序列。数字间以空格分隔。

输出格式：

在一行中输出该树反转后的层序遍历的序列。数字间以1个空格分隔，行首尾不得有多余空格。
输入样例：

7
1 2 3 4 5 6 7
4 1 3 2 6 5 7

输出样例：

4 6 1 7 5 3 2

*/
#include <stdio.h>
#include <stdlib.h>

int pre[35],mid[35],n;
typedef struct bitnode
{
    int value;
    struct bitnode *left,*right;
}BiTNode,*BiTree;
void ReBiTree(BiTree root)
{
    PreInOd(0,n-1,0,n-1,&root);
}

void PreInOd(int i,int j,int k,int h,BiTree *root)
{
    *root=(BiTNode*)malloc(sizeof(BiTNode));
    *root->value=pre[i];
    int m=k;
    while(mid[m]!=pre[i])
        m++;
    if(m==k)
        *root->left=NULL;
    else
        PreInOd(i+1,i+m-k,k,m-1,&(*root->left));
    if(m==h)
        *root->right=NULL;
    else
        PreInOd(i+m-k+1,j,inod,m+1,h,&(*root->right));
}
void Exchange(BiTree root)
{
    BiTNode *p;
    if(root)
    {
        Exchange(root->left);
        Exchange(root->right);
        p=root->left;
        root->left=root->right;
        root->right=p;
    }
}
void LevelOrder(BiTree root)
{
    BiTNode *p[35];
    int front,rear;
    if(root==NULL)
        return;
    front=-1;
    rear=0;
    p[rear]=root;
    while(front!=rear)
    {
        front++;
        printf("%d ",p[front]->value);
        if(p[front]->left!=NULL)
        {
            rear++;
            p[rear]=p[front]->left;
        }
        if(p[front]->right!=NULL)
        {
            rear++;
            p[rear]=p[front]->right;
        }
    }

}
int main()
{
    int i;
    scanf("%d",&n);
    for( i=0;i<n;i++)
        scanf("%d",&mid[i]);
    for( i=0;i<n;i++)
        scanf("%d",&pre[i]);

    BiTree root=NULL;
    ReBiTree(root);
    Exchange(root);
    LevelOrder(root);
    return 0;
}
