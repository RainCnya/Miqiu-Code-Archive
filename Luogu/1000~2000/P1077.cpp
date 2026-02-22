#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const int mod = 1e6 + 7;

ll dp[maxn][maxn];
// dp[i][j] 表示 前i种花 总共放了j个的 总方案数
int a[maxn];
int n, m;

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    dp[0][0] = 1;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 0; j <= m; ++ j )
        {
            for( int k = 0; k <= min( j, a[i] ); ++ k )
            {
                dp[i][j] = ( dp[i][j] + dp[i-1][j-k] ) % mod;
            }
        }
    }

    cout << dp[n][m] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}