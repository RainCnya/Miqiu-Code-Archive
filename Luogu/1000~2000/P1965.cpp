#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

ll n, m, k, x;

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
    
    cin >> n >> m >> k >> x;

    ll ans = ( x + m * qpow( 10, k, n ) ) % n;

    cout << ans << '\n';
    return 0;
}