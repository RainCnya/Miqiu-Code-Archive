#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int n, m;

struct B { int x, y; } b[maxn];

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ; k; k >>= 1, a = a * a % mod )
        if( k & 1 ) res = res * a % mod;
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

ll P( ll n, ll k ) 
{
    if( n < 0 || k < 0 || n < k ) return 0; 
    return fac[n] * inv[n - k] % mod; 
}

bool cmp( B x, B y ) { return x.x < y.x; }

void solve( )
{
    cin >> n >> m;
    bool flag = 0;
    bool ok = 1;
    for( int i = 1; i <= m; ++ i ) 
    {
        cin >> b[i].x >> b[i].y;
        if( b[i].x == 1 )
        {
            flag = 1;
            if( b[i].y != n ) ok = 0;
        }
    }

    if( !ok ) { cout << 0 << '\n'; return ; }
    if( !flag ) b[++ m] = { 1, n };

    sort( b + 1, b + m + 1, cmp );
    
    ll ans = 1;
    for( int i = 1; i < m; ++ i )
    {
        ll x1 = b[i].x, x2 = b[i+1].x;
        ll y1 = b[i].y, y2 = b[i+1].y;
        if( y2 > y1 ) ans = 0;
        
        ll L = x2 - x1;
        ll M = ( n - y2 ) - ( x1 - 1 );

        if( y1 == y2 ) ans = ans * P( M, L ) % mod;
        else ans = ans * ( P( M, L ) - P( M - 1, L ) + mod ) % mod;
    }
    ans = ans * fac[n - b[m].x + 1] % mod;
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    init( maxn - 5 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}