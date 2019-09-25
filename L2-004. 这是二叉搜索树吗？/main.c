/*

一棵二叉搜索树可被递归地定义为具有下列性质的二叉树：对于任一结点，

    其左子树中所有结点的键值小于该结点的键值；
    其右子树中所有结点的键值大于等于该结点的键值；
    其左右子树都是二叉搜索树。

所谓二叉搜索树的“镜像”，即将所有结点的左右子树对换位置后所得到的树。

给定一个整数键值序列，现请你编写程序，判断这是否是对一棵二叉搜索树或其镜像进行前序遍历的结果。

输入格式：

输入的第一行给出正整数N（<=1000）。随后一行给出N个整数键值，其间以空格分隔。

输出格式：

如果输入序列是对一棵二叉搜索树或其镜像进行前序遍历的结果，则首先在一行中输出“YES”，然后在下一行输出该树后序遍历的结果。数字间有1个空格，一行的首尾不得有多余空格。若答案是否，则输出“NO”。
输入样例1：

7
8 6 5 7 10 8 11

输出样例1：

YES
5 7 6 8 11 10 8

输入样例2：

7
8 10 11 8 6 7 5

输出样例2：

YES
11 8 10 7 5 6 8

输入样例3：

7
8 6 8 5 10 9 11

输出样例3：

NO

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *lchild,*rchild;
}Node,*Root;

//root a==Node *a

void postolder()
{

}

int main()
{
    int n,i;
    scanf("%d",&n);
    int list[n];
    for(i=0;i<n;i++)
        scanf("%d",&list[i]);
/*http://blog.csdn.net/weixin_37517391/article/details/64592056
方法1：直接根据树的前序遍历来建树（分两种情况）在建树的过程中，判断是否满足二叉搜索树的条件，如果不满足设置标志位。

然后建树完成以后，对树进行dfs后序遍历，这种方法很暴力，也很容易理解，但是代码有点繁琐。

方法2：直接在前序遍历的结果上进行dfs，分成两个子树进行dfs，在dfs的过程中，记录得到左子树的最大最小值，和右子树的最大最小值

在非镜像的情况下，保证左子树的最大值小于根节点，右子树的最小值大于等于根节点。然后再得到根节点树的最大最小值。

其中根节点树的最大值是max(根节点值，右子树的最大值)

根节点树的最小值是min（根节点值，左子树的最小值）

并且在dfs函数的最后将根节点压入队列里面，输出的时候直接按队列顺序输出就可以了，是不是很巧妙。

在镜像的情况下，类似。*/
    return 0;
}

暴力解决法
#include<stdio.h>
    #include<stdlib.h>

    typedef struct BST* bstree;

    int temp[1010],n;

    struct BST{
        int Weight;
        bstree left;
        bstree right;
    }BST;


    void Insert(bstree T,int data)
    {
        if(T->Weight>data)
        {
            if(T->left==NULL)
            {
                bstree P=(bstree)malloc(sizeof(BST));
                P->left=NULL;
                P->right=NULL;
                P->Weight=data;
                T->left=P;
            }
            else
                Insert(T->left,data);
        }
        else
        {
            if(T->right==NULL)
            {
                bstree P=(bstree)malloc(sizeof(BST));
                P->left=NULL;
                P->right=NULL;
                P->Weight=data;
                T->right=P;
            }
            else
                Insert(T->right,data);
        }
    }

    int aa[1010];
    int num_a;
    void xianxu(bstree T)
    {
        if(T!=NULL)
        {
            aa[num_a++]=T->Weight;
            xianxu(T->left);
            xianxu(T->right);
        }
    }

    int bb[1010];
    int num_b;
    void houxu(bstree T)
    {
        if(T!=NULL)
        {
            bb[num_b++]=T->Weight;
            houxu(T->right);
            houxu(T->left);
        }
    }

    int cc[1010];
    int num_c;
    void houxu_ans(bstree T)
    {
        if(T!=NULL)
        {
            houxu_ans(T->left);
            houxu_ans(T->right);
            cc[num_c++]=T->Weight;
        }
    }

    void huoxu_ans_2(bstree T)
    {
        if(T!=NULL)
        {
            huoxu_ans_2(T->right);
            huoxu_ans_2(T->left);
            cc[num_c++]=T->Weight;
        }
    }

    int main()
    {
        int i;
        scanf("%d",&n);
        for( i=1;i<=n;i++)
            scanf("%d",&temp[i]);

        bstree root;
        root=(bstree)malloc(sizeof(BST));
        root->left=NULL;
        root->right=NULL;
        root->Weight=temp[1];

        for( i=2;i<=n;i++)
            Insert(root,temp[i]);
        num_a=num_b=0;
        xianxu(root);
        houxu(root);

        int flag=1;
        for( i=0;i<num_a;i++)
        {
            if(temp[i+1]!=aa[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            puts("YES");
            num_c=0;
            houxu_ans(root);
            for( i=0;i<num_c;i++)
            {
                if(i) printf(" ");
                printf("%d",cc[i]);
            }
            return 0;
        }
        flag=1;
        for( i=0;i<num_b;i++)
        {
            if(temp[i+1]!=bb[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            puts("YES");
            num_c=0;
            huoxu_ans_2(root);
            for( i=0;i<num_c;i++)
            {
                if(i) printf(" ");
                printf("%d",cc[i]);
            }
            return 0;
        }
        puts("NO");
        return 0;
    }
    */
