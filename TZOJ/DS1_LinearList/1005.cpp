#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* CreateLinkList( int n )
{
    Node *head = new Node( );
    head->next = NULL;
    Node *tail = head;
    for( int i = 1; i <= n; ++ i )
    {
        Node *cur = new Node( );
        cin >> cur->data;
        cur->next = NULL;
        tail->next = cur;
        tail = cur;
    }
    return head;
}

Node *Find( Node *head, int x )
{
    Node *cur = head;
    while( cur->next != NULL && cur->next->data != x ) cur = cur->next;
    return cur;
}

void Delete( Node *p )
{
    Node *tar = p->next;
    p->next = tar->next;
    delete tar;
}