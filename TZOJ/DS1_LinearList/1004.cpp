#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void CreateHeader( Node **head )
{
    *head = (Node *)malloc( sizeof( Node ) );
    (*head)->next = NULL;
}

void Insert( Node *head, int d )
{
    Node *cur = new Node( );
    cur->data = d;
    cur->next = head->next;
    head->next = cur;
}