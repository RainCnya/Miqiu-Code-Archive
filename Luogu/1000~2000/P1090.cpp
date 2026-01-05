#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int h[maxn], sz = 0;
int n;

void up( int u )
{
    while( u / 2 && h[u] < h[u / 2] )
    {
        swap( h[u], h[u / 2] );
        u /= 2;
    }
}

void down( int u )
{
    int v = u * 2;
    while( v <= sz )
    {
        if( v + 1 <= sz && h[v + 1] < h[v] ) v ++;
        if( h[u] <= h[v] ) break;
        swap( h[u], h[v] );
        u = v; v = u * 2;
    }
}

void push( int x )
{
    h[++sz] = x;;
    up( sz );
}

void pop( ) 
{
    h[1] = h[sz --];
    down( 1 );
}

int top( ) 
{
    return h[1];
}

int main( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        push( x );
    }   

    ll ans = 0;
    for( int i = 1; i < n; ++ i )
    {
        ll x = top( ); pop( );
        ll y = top( ); pop( );
        ans += x + y;
        push( x + y );
    }

    cout << ans << '\n';
    return 0;
}