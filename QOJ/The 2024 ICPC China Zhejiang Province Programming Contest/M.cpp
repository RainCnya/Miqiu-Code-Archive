#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void print( __int128 x )
{
    if( x > 9 ) print( x / 10 );
    putchar( x % 10 + '0' );
}

void solve( )
{
    ll n, a, b;
    cin >> n >> a >> b;

    __int128 total = (__int128) n * ( n + 2 ) * ( 2 * n + 1 ) / 8;

    __int128 remove = 0;
    ll m = min( b, a - b + 1 );

    for( ll k = 1; k <= a; ++ k )
    {
        ll cnt = min({ k, m, a - k + 1 });
        if( cnt > 0 ) remove += (__int128) cnt;
    }

    for( ll k = 1; k <= n - a; ++ k )
    {
        ll cnt = min({ k, m, a - k + 1 });
        if( cnt > 0 ) remove += (__int128) cnt;
    }

    print( total - remove );
    putchar( '\n' );
    return;
}

int main( )
{
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}