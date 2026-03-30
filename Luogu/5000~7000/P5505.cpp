#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;
const int mod = 1e9 + 7;

ll C[maxn][maxn];
int a[maxn];
int n, m;

void init( int N )
{
    for( int i = 0; i <= N; ++ i ) {
        C[i][0] = 1;
        for( int j = 1; j <= i; ++ j )
            C[i][j] = ( C[i-1][j-1] + C[i-1][j] ) % mod;
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    init( maxn - 5 );

    cin >> n >> m;
    for( int i = 1; i <= m; ++ i ) cin >> a[i];

    ll ans = 0;
    
    for( int i = 0; i < n; ++ i )
    {
        ll cur = C[n][i];
        for( int j = 1; j <= m; ++ j )
        {
            cur = ( cur * C[a[j] + n-i-1][n-i-1] ) % mod;
        }
        if( i % 2 == 0 ) ans = ( ans + cur ) % mod;
        else ans = ( ans - cur + mod ) % mod;
    }

    cout << ans << '\n';
    return 0;
}