#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n, x, y;
int p[maxn];

int find( const vector< int > &t )
{
    int n = t.size( );
    int res = 0;
    for( int i = 1; i < n; ++ i )
    {
        for( int k = 0; k < n; ++ k )
        {
            if( t[(res + k) % n] > t[(i + k) % n] ) 
            {
                res = i;
                break;
            }
            else if( t[(res + k) % n] < t[(i + k) % n] )
            {
                break;
            }
        }
    }
    return res;
}

void solve( )
{
    cin >> n >> x >> y;
    for( int i = 1; i <= n; ++ i ) cin >> p[i];

    vector< int > a, b;
    for( int i = 1; i <= n; ++ i )
    {
        if( i <= x || i > y ) a.push_back( p[i] );
        else b.push_back( p[i] );
    }

    int st = find( b );
    int lenb = b.size( );
    vector< int > bb;
    for( int i = 0; i < lenb; ++ i )
    {
        bb.push_back( b[(st + i) % lenb] );
    }

    int lena = a.size( );
    int pos = lena;
    for( int i = 0; i < lena; ++ i )
    {
        if( bb[0] < a[i] )
        {
            pos = i;
            break;
        }
    }

    for( int i = 0; i < pos; ++ i ) cout << a[i] << ' ';
    for( int i = 0; i < lenb; ++ i ) cout << bb[i] << ' ';
    for( int i = pos; i < lena; ++ i ) cout << a[i] << ' ';
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}