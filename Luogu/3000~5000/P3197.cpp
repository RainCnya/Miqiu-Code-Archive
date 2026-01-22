#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 100003;
ll n, m;

ll qpow( ll base, ll k, ll mod )
{
    ll res = 1;
    while( k )
    {
        if( k & 1 ) res = ( res * base ) % mod;
        base = ( base * base ) % mod;
        k >>= 1;
    }
    return res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> m >> n;

    ll sum = qpow( m, n, mod );
    ll del = ( m * qpow( m - 1, n - 1, mod ) ) % mod;

    ll ans = ( sum - del + mod ) % mod;
    cout << ans << '\n';
    return 0;
}