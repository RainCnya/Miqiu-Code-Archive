#include <bits/stdc++.h>
using namespace std;

typedef int Elemtype;
typedef struct node {
    Elemtype data;
    struct node *next;
} Node;

void Insert( Node* head, int pos, Elemtype x )
{
    Node* p = head;
    int i;
    for( i = 0; i < pos - 1; ++ i ) p = p->next;
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = x;
    q->next = p->next;
    p->next = q;
}

void Delete( Node* head, int pos )
{
    Node* p = head;
    int i;
    for( i = 0; i < pos - 1; ++ i ) p = p->next;
    p->next = p->next->next;
}

int Find( Node* head, Elemtype x )
{
    Node* p = head;
    int pos = 0;
    while( p->next != NULL )
    {
        p = p->next;
        if( p->data == x ) return pos + 1;
        pos ++;
    }
    return -1;
}

void Update( Node* head, int pos, Elemtype x )
{
    Node* p = head;
    int i;
    for( i = 1; i < pos; ++ i ) p = p->next;
    p->next->data = x;
}

void Reverse( Node* head )
{
    Node* p = head->next;
    head->next = NULL;
    while( p != NULL )
    {
        Node* q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}