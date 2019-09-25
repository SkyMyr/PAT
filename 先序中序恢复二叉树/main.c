    #include <stdlib.h>
    #include<stdio.h>
    #include <string.h>

    #define  N  100

    typedef struct BiTNode
    {
        char data;
        struct BiTNode *lchild,*rchild;
    } BiTNode,* BITree;
        //�������
    void preOrder(BiTNode*root)
    {
        if (root==NULL)
        {
            return;
        }
        printf("%c ",root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
    //�������
    void inOrder(BiTNode*root)
    {
        if (root==NULL)
        {
            return;
        }
        inOrder(root->lchild);
        printf("%c ",root->data);
        inOrder(root->rchild);
    }

    /************************************************************************/
    /* �㷨
    1��ͨ����������ҵ������A����ͨ��A�����������λ���ҳ���������������
    2����A���������У����������ĸ���㣨���������ң���ת����1
    3����A���������У����������ĸ���㣨���������ң���ת����1                                                                     */
    /************************************************************************/
    //������������������������������
    BiTNode* createBiTree(char *pre, char *in, int n)
    {
        int i = 0;
        int n1 = 0,n2 = 0;
        int m1 = 0,m2 = 0;
        BiTNode*node = NULL;
        char lpre[N],rpre[N];
        char lin[N],rin[N];
        if (n == 0)
        {
            return NULL;
        }
        node = (BiTNode*)malloc(sizeof(BiTNode));
        if (node==NULL)
        {
            return NULL;
        }
        memset(node,0,sizeof(BiTNode));
        //�������еĵ�һ��Ԫ�ر�Ϊ�����
        node->data = pre[0];
        //���ݸ���㽫�������з�Ϊ��������������
        for (i = 0;i<n;i++)
        {
            if ((i<=n1)&&(in[i]!=pre[0]))
            {
                lin[n1++] = in[i];
            }
            else if(in[i]!=pre[0])
            {
                rin[n2++] = in[i];
            }
        }
        //���������������еĳ��ȵ����������еĳ���
        //��������������������ٺ�����,�������������� ���������������ĳ��ȶ��ǹ̶���
        //���� ��i=1��ʼ ��Ϊ��������ĵ�һ���Ǹ�
        for (i = 1;i < n;i++)
        {
            if (i< (n1+1))//n1�������������ĳ���
            {
                lpre[m1++] = pre[i];
            }
            else
            {
                rpre[m2++] = pre[i];
            }
        }
        node->lchild = createBiTree(lpre,lin,n1);
        node->rchild = createBiTree(rpre,rin,n2);

        return node;
    }

    int main()
    {
        char preNode[N];
        char inNode[N];

        BiTNode* root=NULL;
        int n = 0;
        char ch;
        printf("��������������\n");
        while((ch = getchar())&&ch!='\n')
            preNode[n++] = ch;
        printf("��������������\n");
        n = 0;
        while((ch = getchar())&&ch!='\n')
            inNode[n++] = ch;

        int i,n;
        scanf("%d",&n);
        for( i=0;i<n;i++)
            scanf("%c",&inNode[i]);
        for( i=0;i<n;i++)
            scanf("%c",&preNode[i]);
        root = createBiTree(preNode,inNode,n);

        printf("��������\n");
        preOrder(root);
        printf("\n��������\n");
        inOrder(root);

        return 0;
    }
