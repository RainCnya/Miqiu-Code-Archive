#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ; k; k >>= 1, a = a * a % mod )
        if( k & 1 ) res = res * a % mod;
    return res;
}

ll d[maxn];
ll fac[maxn], inv[maxn];

void init( int N )
{
    d[0] = d[1] = 0, d[2] = 1, d[3] = 2;
    for( int i = 4; i <= N; ++ i ) d[i] = ( i - 1 ) * ( d[i-1] + d[i-2] ) % mod;
    fac[0] = 1;
    for( int i = 1; i <= N; ++ i ) fac[i] = fac[i-1] * i % mod;
    inv[N] = qpow( fac[N], mod - 2 );
    for( int i = N - 1; i >= 0; -- i ) inv[i] = inv[i+1] * ( i + 1 ) % mod;
}

ll get_C( ll n, ll m ) 
{ 
    if( n < m ) return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod; 
}

void solve( )
{
    int n, m;
    cin >> n >> m;
    if( n == m ) { cout << 1 << '\n'; return ; }
    cout << ( d[n - m] * get_C( n, m ) % mod ) << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    init( maxn - 5 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}