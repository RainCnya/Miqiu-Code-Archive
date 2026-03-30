#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 50;
const int mod = 998244353;

int n;
int a[maxn];
ll fac[maxn];
ll inv[maxn];

ll qpow( ll base, ll k )
{
    ll res = 1;
    base %= mod;
    while( k )
    {
        if( k & 1 ) res = ( res * base ) % mod;
        base = ( base * base ) % mod;
        k >>= 1;
    }
    return res;
}

void init( )
{
    fac[0] = 1;
    for( int i = 1; i < maxn; ++ i ) 
        fac[i] = ( fac[i-1] * i ) % mod;
    inv[maxn - 1] = qpow( fac[maxn - 1], mod - 2 );
    for( int i = maxn - 2; i >= 0; -- i ) 
        inv[i] = ( inv[i + 1] * ( i + 1 ) ) % mod;
}

ll per( int n, int r )
{
    return ( fac[n] * inv[n - r] ) % mod;
}

void solve( )
{
    cin >> n;
    ll sum = 0;
    for( int i = 0; i <= n; ++ i )
    {
        cin >> a[i];
        sum += a[i];
    }
    ll q = sum / n;
    int r = sum % n;

    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] > q + 1 )
        {
            cout << 0 << '\n';
            return;
        }
        if( a[i] == q + 1 ) cnt ++;
    }

    ll res = per( r, cnt );
    res = ( res * fac[n - cnt] ) % mod;
    cout << res << '\n';
}

int main( )
{
    init( );
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
