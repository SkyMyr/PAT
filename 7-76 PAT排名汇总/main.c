#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node *Node;
struct node {
    char identifier[14];//考号，第二顺位排序依据
    int score;//分数，第一顺位排序依据
    int kaodian;//隶属考点
    int Sort_kaodian;//考点内排名
    int Sort_ToTle;
}*Students[30001];

int comp(const void*a,const void*b) {
    Node x=*(Node*)a;
    Node y=*(Node*)b;

    if(x->score!=y->score) {
        return y->score-x->score;
    } else {

        return strcmp(x->identifier,y->identifier);
    }

}

int main() {
    int i,j;
    int n;//<=100
    scanf("%d",&n);
    int left=0;
    int sum=0;
    for( i=0; i<n; i++) {
        int m;//<=300
        scanf("%d",&m);
        left=sum;
        for( j=0; j<m; j++) {
            Students[sum]=(Node)malloc(sizeof(struct node));
            scanf("%s%d",&Students[sum]->identifier,&Students[sum]->score);
            Students[sum++]->kaodian=i+1;
        }
        qsort(&Students[left],m,sizeof(Node),comp);
        Students[left]->Sort_kaodian=1;
        for( j=left+1; j<sum; j++) {
            if(Students[j]->score==Students[j-1]->score)Students[j]->Sort_kaodian=Students[j-1]->Sort_kaodian;
            else Students[j]->Sort_kaodian=j-left+1;
        }
    }
    printf("%d\n",sum);
    qsort(Students,sum,sizeof(Node),comp);
    Students[0]->Sort_ToTle=1;

    for( i=0; i<sum; i++) {
        printf("%s",Students[i]->identifier);
        if(i) {
            if(Students[i]->score!=Students[i-1]->score) {
                Students[i]->Sort_ToTle=i+1;
            } else {
                Students[i]->Sort_ToTle=Students[i-1]->Sort_ToTle ;
            }
        }
        printf(" %d",Students[i]->Sort_ToTle );
        printf(" %d",Students[i]->kaodian);
        printf(" %d\n",Students[i]->Sort_kaodian);
    }




    return 0;
}
