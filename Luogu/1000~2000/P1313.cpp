#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;
const int mod = 10007;

ll a, b, k, n, m;

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ; k; k >>= 1, a = a * a % mod )
        if( k & 1 ) res = res * a % mod;
    return res;
}

ll C[maxn][maxn];

void init( )
{
    for( int i = 0; i <= k; ++ i )
    {
        for( int j = 0; j <= k; ++ j )
        {
            if( j == 0 || j == i ) C[i][j] = 1;
            else C[i][j] = ( C[i - 1][j - 1] + C[i - 1][j] ) % mod;
        }
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    cin >> a >> b >> k >> n >> m;
    init( );
    ll ans = qpow( a, n ) % mod * qpow( b, m ) % mod;
    ans = ans * C[k][m] % mod;
    cout << ans << '\n';
    return 0;
}