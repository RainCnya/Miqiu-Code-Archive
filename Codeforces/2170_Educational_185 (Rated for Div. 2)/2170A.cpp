#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int n;

bool check( int cur )
{
    return 1 <= cur && cur <= n;
}

int c( int x, int y )
{
    return ( x - 1 ) * n + y;
}

int calc( int x, int y )
{
    if( !check( x ) || !check( y ) ) return 0;
    int res = c( x, y );
    if( check( x + 1 ) ) res += c( x + 1, y );
    if( check( y + 1 ) ) res += c( x, y + 1 );
    if( check( x - 1 ) ) res += c( x - 1, y );
    if( check( y - 1 ) ) res += c( x, y - 1 );
    return res;
}

void solve( )
{
    cin >> n;
    int ans = -1;
    ans = max( ans, calc( n, n ) );
    ans = max( ans, calc( n-1, n ) );
    ans = max( ans, calc( n, n-1 ) );
    ans = max( ans, calc( n-1, n-1 ) );
    cout << ans << '\n';
}

int main( )
{
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }

    return 0;
}