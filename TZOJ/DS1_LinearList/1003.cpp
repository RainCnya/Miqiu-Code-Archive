#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *CreateLinkList(int n)
{
    Node *head = NULL, *tail = NULL;
    for(int i = 1; i <= n; ++ i)
    {
        Node *q = (Node *)malloc(sizeof(Node));
        cin >> q->data;
        q->next = NULL;
        if( head == NULL ) head = tail = q;
        else tail->next = q, tail = q;
    }
    return head;
}