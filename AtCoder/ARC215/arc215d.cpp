#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e7 + 5;
const int mod = 1e9 + 7;

ll N, M;

ll fac[maxn], inv[maxn];

ll qpow( ll a, ll b )
{
    ll res = 1;
    while( b )
    {
        if( b & 1 ) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll C( ll n, ll k )
{
    if( n < k ) return 0;
    return ( fac[n] * inv[k] % mod ) * inv[n - k] % mod;
}

void init( )
{
    fac[0] = inv[0] = 1;
    for( int i = 1; i < maxn; ++ i ) fac[i] = ( fac[i - 1] * i ) % mod;
    inv[maxn - 1] = qpow( fac[maxn - 1], mod - 2 );
    for( int i = maxn - 2; i >= 1; -- i ) inv[i] = ( inv[i + 1] * (i + 1) ) % mod;
}

ll calc( ll x, ll y )
{
    ll res = 0;
    for( int i = M + 1; i <= 2 * M; ++ i )
    {
        ll t1 = C( i + (x - 1), (x - 1) );
        ll t2 = C( (2 * M - i) + (y + 1), (y + 1) );
        res = ( res + t1 * t2 ) % mod;
    }
    return res;
}

void solve( )
{
    cin >> N >> M;

    int cnt1 = N / 2, cnt2 = ( N + 1 ) / 2 - 1;

    ll ans = C( 2 * M + N, N );

    ans = ( ans - calc( cnt1, cnt2 ) + mod ) % mod;
    ans = ( ans - calc( cnt2, cnt1 ) + mod ) % mod;

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init( );
    solve( );
    return 0;
}