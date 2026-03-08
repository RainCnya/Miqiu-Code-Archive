#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll x, y, m, n, l;

ll exgcd( ll a, ll b, ll &x, ll &y )
{
    if( b == 0 ) { x = 1, y = 0; return a; }
    ll d = exgcd( b, a % b, y, x );
    y -= a / b * x;
    return d;
}

ll k, z, d;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> x >> y >> m >> n >> l;

    int f = 1;
    if( m < n ) { f = -1; swap( m, n ); }

    d = exgcd( m - n, l, k, z );

    if( ( y - x ) % d != 0 )
    {
        cout << "Impossible" << '\n';
        return 0;
    }

    k = k * f * ( y - x ) / d;
    k = ( k % ( l / d ) + ( l / d ) ) % ( l / d );

    cout << k << '\n';
    return 0;
}