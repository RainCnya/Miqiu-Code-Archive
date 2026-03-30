#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ; k; k >>= 1, a *= a )
        if( k & 1 ) res *= a;
    return res;
}

ll C( ll n, ll m )
{
    if( n < m ) return 0;
    ll res = 1;
    for( ll i = n; i > n - m; -- i )
    {
        res *= i;
        res /= (n - i + 1);
    }
    return res;
}

int main( )
{
    int n, r;
    cin >> n >> r;
    ll ans = 0;

    for( int k = 0; k <= r - 1; ++ k )
    {
        ans += ( (k & 1) ? -1 : 1 ) * C( r, k ) * qpow( r - k, n );
    }

    cout << ans << '\n';
    return 0;
}