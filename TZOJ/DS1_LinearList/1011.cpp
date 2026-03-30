#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *data;
    int length;
}SeqList;

void CreateSeqList( SeqList &lst, char s[] )
{
    lst.length = strlen( s );
    lst.data = ( char* )malloc( sizeof( char ) * lst.length );
    for( int i = 0; i < lst.length; i ++ ) lst.data[i] = s[i];
}

void Insert( SeqList &lst, char c )
{
    char *old = lst.data;
    int len = lst.length + 1;
    lst.data = ( char* )malloc( sizeof( char ) * len );
    lst.data[0] = c;
    for( int i = 0; i < lst.length; i ++ ) lst.data[i+1] = old[i];
    lst.length = len;
    free( old );
}