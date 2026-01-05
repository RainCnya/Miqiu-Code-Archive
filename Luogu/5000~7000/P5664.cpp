#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 105;
const int maxm = 2005;

int a[maxn][maxm];
long long sum[maxn];
long long dp[maxn][maxn<<1];
int n, m;

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> a[i][j];
            sum[i] = ( sum[i] + a[i][j] ) % mod;
        }
    }

    long long total = 1;
    for( int i = 1; i <= n; ++ i )
    {
        total = ( total * ( sum[i] + 1 ) ) % mod;
    }
    total = ( total - 1 + mod ) % mod;


    long long res = 0;
    for( int c = 1; c <= m; ++ c )
    {
        memset( dp, 0, sizeof( dp ) );
        dp[0][n] = 1;
        
        for( int i = 1; i <= n; ++ i )
        {
            for( int j = n - i; j <= n + i; ++ j )
            {
                dp[i][j] = dp[i-1][j];

                if( j - 1 >= 0 )
                    dp[i][j] = ( dp[i][j] + dp[i-1][j-1] * a[i][c] ) % mod;
                if( j + 1 <= 2 * n )
                    dp[i][j] = ( dp[i][j] + dp[i-1][j+1] * ( sum[i] - a[i][c] + mod ) % mod ) % mod;
            }
        }
    
        for( int j = n + 1; j <= 2 * n; ++ j )
        {
            res = ( res + dp[n][j] ) % mod;
        }
    }

    

    long long ans = ( total - res + mod ) % mod;

    cout << ans << '\n';

    return 0;
}