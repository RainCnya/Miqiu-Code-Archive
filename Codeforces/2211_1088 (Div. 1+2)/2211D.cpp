#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int n;
ll b[maxn], a[maxn];
ll bitcnt[32];

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ll kk = k; kk; kk >>= 1, a = a * a % mod )
        if( kk & 1 ) res = res * a % mod;
    return res;
}

ll fac[maxn], inv[maxn];

void init( int N )
{
    fac[0] = 1;
    for( int i = 1; i <= N; ++ i ) fac[i] = fac[i - 1] * i % mod;
    inv[N] = qpow( fac[N], mod - 2 );
    for( int i = N - 1; i >= 0; -- i ) inv[i] = inv[i + 1] * ( i + 1 ) % mod;
}

ll getC( int n, int m )
{
    if( n < m ) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    for( int i = 0; i <= 31; ++ i ) bitcnt[i] = 0;

    for( int i = n; i >= 1; -- i )
    {
        if( b[i] == 0 ) continue;
        ll cur = b[i];
        for( int j = 0; j < 31; ++ j )
        {
            if( ( cur >> j ) & 1 ) bitcnt[j] = i;
        }

        for( int k = 1; k < i; ++ k )
        {
            ll tmp = ( cur * getC( i, k ) ) % mod;
            b[k] = ( b[k] - tmp + mod ) % mod;
        }
    }

    for( int i = 1; i <= n; ++ i ) a[i] = 0;

    for( int j = 0; j < 31; ++ j )
    {
        for( int i = 1; i <= bitcnt[j]; ++ i )
        {
            a[i] |= ( 1ll << j );
        }
    }

    for( int i = 1; i <= n; ++ i ) cout << a[i] << ' ';
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    init( maxn - 5 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}