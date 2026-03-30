/**
 * 线性表通用标准模板 (符合个人编码习惯版)
 * 包含：顺序表、带头节点单链表、双向循环链表、静态链表
 */

#include <bits/stdc++.h>
using namespace std;

// =============================================================================
// 1. 顺序表 (SeqList)
// =============================================================================

const int MAXN = 200 + 10;
typedef int Elemtype;

typedef struct {
    Elemtype *data;
    int length;
} SeqList;

void CreateSeqList( SeqList &L )
{
    L.data = ( Elemtype * )malloc( sizeof( Elemtype ) * MAXN );
    L.length = 0;
}

void InitSeqList( SeqList &L )
{
    cin >> L.length;
    for( int i = 0; i < L.length; ++ i ) cin >> L.data[i];
}

void InsertSeqList( SeqList &L, int pos, Elemtype x )
{
    if( pos < 0 || pos > L.length ) return;
    for( int i = L.length; i >= pos + 1; -- i ) L.data[i] = L.data[i - 1];
    L.data[pos] = x;
    L.length++;
}

void DeleteSeqList( SeqList &L, int pos )
{
    if( pos < 0 || pos >= L.length ) return;
    for( int i = pos; i < L.length - 1; ++ i ) L.data[i] = L.data[i + 1];
    L.length--;
}

void ReverseSeqList( SeqList &L )
{
    for( int i = 0; i < L.length / 2; ++ i )
        swap( L.data[i], L.data[L.length - 1 - i] );
}

// =============================================================================
// 2. 带头节点单链表 (LinkList)
// =============================================================================

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

Node* Find( Node *head, int x )
{
    Node *cur = head;
    while( cur->next != NULL && cur->next->data != x ) cur = cur->next;
    return cur;
}

void DeleteNode( Node *p ) // 删除 p 的后继
{
    if( p == NULL || p->next == NULL ) return;
    Node *tar = p->next;
    p->next = tar->next;
    delete tar;
}

void ReverseLinkList( Node *head )
{
    Node *p = head->next;
    head->next = NULL;
    while( p != NULL )
    {
        Node *q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
}

// =============================================================================
// 3. 循环单链表 (Circular LinkList)
// =============================================================================

Node* CreateCircularList( int n )
{
    Node *head = ( Node * )malloc( sizeof( Node ) );
    head->next = head;
    Node *tail = head;
    for( int i = 1; i <= n; ++ i )
    {
        Node *cur = ( Node * )malloc( sizeof( Node ) );
        cin >> cur->data;
        cur->next = head;
        tail->next = cur;
        tail = cur;
    }
    return head;
}

// =============================================================================
// 4. 静态链表 (Static List)
// =============================================================================

const int MAXSIZE = 100;

struct SNode {
    int data;
    int cur;
};

void InitSList( SNode a[] )
{
    for( int i = 0; i < MAXSIZE - 1; ++ i ) a[i].cur = i + 1;
    a[MAXSIZE - 1].cur = 0;
}

int Alloc( SNode a[] )
{
    int p = a[0].cur;
    if( p == 0 ) return -1;
    a[0].cur = a[p].cur;
    return p;
}

void Free( SNode a[], int k )
{
    a[k].cur = a[0].cur;
    a[0].cur = k;
}