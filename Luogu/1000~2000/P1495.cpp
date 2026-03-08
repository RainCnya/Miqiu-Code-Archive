#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 10 + 5;

ll a[maxn], m[maxn];
int n;

ll qmul( ll a, ll b, ll mod )
{
    ll res = 0;
    while( b ) 
    {
        if( b & 1 ) res = ( res + a ) % mod;
        a = ( a + a ) % mod;
        b >>= 1;
    }
    return res;
}

ll exgcd( ll a, ll b, ll &x, ll &y )
{
    if( b == 0 ) { x = 1, y = 0; return a; }
    ll d = exgcd( b, a % b, y, x );
    y -= a / b * x;
    return d;
}

ll crt( int n )
{
    ll M = 1, ans = 0;
    for( int i = 1; i <= n; ++ i ) M *= m[i];

    for( int i = 1; i <= n; ++ i )
    {
        ll Mi = M / m[i];
        ll ti, y;
        exgcd( Mi, m[i], ti, y );
        ti = ( ti % m[i] + m[i] ) % m[i];
        ans = ( ans + qmul( qmul( a[i], Mi, M ), ti, M ) ) % M;
    }
    return ( ans + M ) % M;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> m[i] >> a[i];
    }
    cout << crt( n ) << '\n';
    return 0;
}