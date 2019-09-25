#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node *Node;
struct Node
{
    int data;
    Node Next;
};
Node CList()
{
    int d;
    Node head = (Node)malloc(sizeof(struct Node)),q;
    head -> Next = NULL;
    q = head;
    while(~scanf("%d",&d)&&d!=-1)
    {
        Node p = (Node)malloc(sizeof(struct Node));
        p -> data = d;
        p -> Next = NULL;
        q -> Next = p;
        q = p;
    }
    return head;
}
Node Intersection(Node a,Node b)
{
    a = a -> Next;
    b = b -> Next;
    Node head = (Node)malloc(sizeof(struct Node));
    head -> Next = NULL;
    Node q = head;
    while(a && b)
    {
        if(a == NULL || a -> data > b -> data)
        {
            b = b -> Next;
        }
        else if(b == NULL || b -> data > a -> data)
        {
            a = a -> Next;
        }
        else
        {
            Node p = (Node)malloc(sizeof(struct Node));
            p -> Next = NULL;
            p -> data = b -> data;
            q -> Next = p;
            q = p;
            a = a -> Next;
            b = b -> Next;
        }
    }
    return head;
}
void printL(Node a)
{
    a = a -> Next;
    if(a == NULL)printf("NULL");
    int flag = 0;
    while(a)
    {
        if(flag)
            printf(" %d",a -> data);
        else
            printf("%d",a -> data);
        a = a -> Next;
        flag = 1;
    }
}
int main()
{
    Node a = CList();
    Node b = CList();
    Node c = Intersection(a,b);
    printL(c);
}
