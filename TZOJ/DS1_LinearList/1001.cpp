#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10;

typedef int Elemtype;
typedef struct {
    Elemtype *data;
    int length;
} SeqList;

void CreateSeqList( SeqList &L )
{
    L.data = (Elemtype *)malloc(sizeof(Elemtype) * maxn);
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

void GetElemInSeqList( SeqList &L, int pos, Elemtype &x )
{
    if( pos < 0 || pos >= L.length ) return;
    x = L.data[pos];
}

int FindInSeqList( SeqList &L, Elemtype x )
{
    for( int i = 0; i < L.length; ++ i )
        if( L.data[i] == x ) return i;
    return -1;
}

void ReverseSeqList( SeqList &L )
{
    for( int i = 0; i < L.length / 2; ++ i )
        swap( L.data[i], L.data[L.length - 1 - i] );
}