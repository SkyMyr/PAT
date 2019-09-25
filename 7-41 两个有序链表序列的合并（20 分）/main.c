#include <stdio.h>
#include <stdlib.h>
typedef struct node *Node;
struct node {
    int Data;
    Node Next;
} ;
Node Scan(void) {
    struct node head;
    Node U=&head;
    head.Next =NULL;
    int num ;
    while(1) {
        scanf("%d",&num);
        if(num!=-1) {

            U->Next =(Node)malloc(sizeof(struct node));
            U->Next ->Data =num;
            U=U->Next ;
        } else break;
    }
    U->Next =NULL;
    return head.Next ;
}

int main() {
    Node Link1=Scan();
    Node Link2=Scan();
    int flag=0;
    while(Link1&&Link2) {
        if(Link1->Data >Link2->Data) {
            if(flag)printf(" ");
            else flag=1;
            printf("%d",Link2->Data );
            Link2=Link2->Next ;
        } else {
            if(flag)printf(" ");
            else flag=1;
            printf("%d",Link1->Data );
            Link1=Link1->Next ;
        }
    }
    while(Link1) {
        if(flag)printf(" ");
        else flag=1;
        printf("%d",Link1->Data );
        Link1=Link1->Next ;
    }
    while(Link2) {
        if(flag)printf(" ");
        else flag=1;
        printf("%d",Link2->Data );
        Link2=Link2->Next ;
    }
    if(!flag)printf("NULL");
    return 0;
}
