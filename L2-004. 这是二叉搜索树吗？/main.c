/*

һ�ö����������ɱ��ݹ�ض���Ϊ�����������ʵĶ�������������һ��㣬

    �������������н��ļ�ֵС�ڸý��ļ�ֵ��
    �������������н��ļ�ֵ���ڵ��ڸý��ļ�ֵ��
    �������������Ƕ�����������

��ν�����������ġ����񡱣��������н������������Ի�λ�ú����õ�������

����һ��������ֵ���У��������д�����ж����Ƿ��Ƕ�һ�ö������������侵�����ǰ������Ľ����

�����ʽ��

����ĵ�һ�и���������N��<=1000�������һ�и���N��������ֵ������Կո�ָ���

�����ʽ��

������������Ƕ�һ�ö������������侵�����ǰ������Ľ������������һ���������YES����Ȼ������һ�����������������Ľ�������ּ���1���ո�һ�е���β�����ж���ո������Ƿ��������NO����
��������1��

7
8 6 5 7 10 8 11

�������1��

YES
5 7 6 8 11 10 8

��������2��

7
8 10 11 8 6 7 5

�������2��

YES
11 8 10 7 5 6 8

��������3��

7
8 6 8 5 10 9 11

�������3��

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
����1��ֱ�Ӹ�������ǰ�������������������������ڽ����Ĺ����У��ж��Ƿ����������������������������������ñ�־λ��

Ȼ��������Ժ󣬶�������dfs������������ַ����ܱ�����Ҳ��������⣬���Ǵ����е㷱����

����2��ֱ����ǰ������Ľ���Ͻ���dfs���ֳ�������������dfs����dfs�Ĺ����У���¼�õ��������������Сֵ�����������������Сֵ

�ڷǾ��������£���֤�����������ֵС�ڸ��ڵ㣬����������Сֵ���ڵ��ڸ��ڵ㡣Ȼ���ٵõ����ڵ����������Сֵ��

���и��ڵ��������ֵ��max(���ڵ�ֵ�������������ֵ)

���ڵ�������Сֵ��min�����ڵ�ֵ������������Сֵ��

������dfs��������󽫸��ڵ�ѹ��������棬�����ʱ��ֱ�Ӱ�����˳������Ϳ����ˣ��ǲ��Ǻ����

�ھ��������£����ơ�*/
    return 0;
}

���������
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
