#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* CreateLinkList( int n )
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = head;
    Node *tail = head;

    int i;
    for( i = 1; i <= n; ++ i )
    {
        Node *cur = (Node *)malloc(sizeof(Node));
        scanf( "%d", &cur->data );
        cur->next = head;
        tail->next = cur;
        tail = cur;
    }
    return head;
}

// 循环输出链表
void PrintLinkList( Node *head, int x )
{
    Node *st = head->next;
    while( st != head && st->data != x ) st = st->next;

    Node *p = st;
    while( 1 )
    {
        if( p != head ) 
        {
            printf("%d", p->data);
            if( p->next != st ) printf(" ");
        }
        p = p->next;
        if( p == st ) break;
    }
    printf("\n");
}

void Destroy(Node* head)
{
    Node *p;
    while(head->next!=head)
    {
        p = head->next;
        head->next = p->next;
        free(p);
    }
    free(head);
}

int main()
{
    int n, x;
    scanf("%d", &n);
    Node *head = CreateLinkList(n);
    while(scanf("%d", &x)!=EOF)
    {
        PrintLinkList(head, x);
    }
    Destroy(head);
    return 0;
}
