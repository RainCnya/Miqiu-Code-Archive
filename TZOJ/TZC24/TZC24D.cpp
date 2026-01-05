#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const int mod = 998244353;

ll fac[maxn];
ll inv[maxn];
ll a[maxn];
int n;

ll qpow( ll x, ll k )
{
    ll res = 1;
    while( k )
    {
        if( k & 1 ) res = res * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return res;
}

void init( )
{
    fac[0] = 1;
    for( int i = 1; i < maxn; ++ i )
    {
        fac[i] = fac[i-1] * i % mod;
    }

    inv[maxn-1] = qpow( fac[maxn-1], mod - 2 );
    for( int i = maxn - 2; i >= 0; -- i )
    {
        inv[i] = inv[i+1] * ( i + 1 ) % mod;
    }
}

ll getC( int n, int m )
{
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}

int main( )
{
    init( );

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1 );

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans = ( ans + getC( n, i ) * a[i] ) % mod;
    }

    cout << ans << '\n';
    return 0;
}