#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 5;

struct Edge { int u, v; };

vector< Edge > edges;

int n;

bool ask( int u, int v )
{
    cout << "? " << u << ' ' << v << endl;
    int res;
    cin >> res;
    return res;
}

void print( int x )
{
    cout << "! " << x << endl;
}

void solve( )
{
    cin >> n;
    edges.clear( );

    for( int i = 1; i + 1 <= n; i += 2 )
    {
        if( ask( i, i + 1 ) ) edges.push_back({ i, i + 1 });
    }

    if( edges.size( ) >= 2 )
    {
        print( 1 );
        return;
    }

    if( edges.size( ) == 1 )
    {
        auto [u, v] = edges[0];
        int x = -1, y = -1;
        for( int i = 1; i <= n; ++ i )
        {
            if( i != u && i != v )
            {
                if( x == -1 ) x = i;
                else if( y == -1 ) y = i;
            }
        }

        if( ask( u, x ) )
        {
            if( ask( u, y ) ) print( 2 );
            else print( 1 );
            return;
        }
        else if( ask( v, x ) )
        {
            if( ask( v, y ) ) print( 2 );
            else print( 1 );
            return;
        }
        print( 1 );
        return;
    }

    if( edges.size( ) == 0 )
    {
        if( n % 2 == 0 )
        {
            print( 1 );
            return;
        }
        else 
        {
            int cnt = ask( n, 1 ) + ask( n, 2 ) + ask( n, 3 );
            if( cnt == 3 ) print( 2 );
            else print( 1 );
            return;
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}