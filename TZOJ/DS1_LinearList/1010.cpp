#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    int cur;
} Node;

const int maxSize = 100;
// Node a[maxSize];

int Alloc( Node a[] )
{
    int p = a[0].cur;
    if( p == 0 ) return -1;
    a[0].cur = a[p].cur;
    return p;
}

int Init( Node a[ ] ) 
{
    int n, i;
    scanf("%d", &n);
    int head = Alloc( a ), pre = head;
    a[head].data = 0;
    a[head].cur = 0;
    for( i = 0; i < n; ++ i ) 
    {
        int p = Alloc( a );
        scanf("%d", &a[p].data);
        a[p].cur = 0;
        a[pre].cur = p;
        pre = p;
    }
    return head;
}

int Find( Node a[], int head, int pos )
{
    int p = head, i;
    for( i = 1; i <= pos; ++ i )
    {
        p = a[p].cur;
        if( p == 0 ) return -1;
    }
    return p;
}

void Insert( Node a[], int head, int pos, int x ) 
{
    int p = Find( a, head, pos - 1 );
    if( p == -1 ) return ;
    int q = Alloc( a );
    a[q].data = x;
    a[q].cur = a[p].cur;
    a[p].cur = q;
}

void Delete( Node a[], int head, int x ) 
{
    int temp = a[head].cur;
    if( temp == 0 ) { printf("Error\n"); return ; }

    while( a[temp].data != x )
    {
        temp = a[temp].cur;
        if( temp == 0 ) { printf("Error\n"); return ; }
    }
    int del = temp;
    temp = head;
    while( a[temp].cur != del ) temp = a[temp].cur;

    a[temp].cur = a[del].cur;
    a[del].cur = a[0].cur;
    a[0].cur = del;
}