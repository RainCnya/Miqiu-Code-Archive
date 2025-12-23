#include<bits/stdc++.h>
using namespace std;

const int maxn = 305;

long long dp[maxn][maxn];
// dp[i][j] 表示 [l,r] 的最大值
long long f[maxn][maxn];
// f[l][r] 表示 [l,r] 中最大值
long long g[maxn][maxn][maxn];
// g[i][j][k] 表示 [i,j] 中包括 k 的最大值

int n, m;

int main()
{	
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int w, l, r;
        cin >> w >> l >> r;
        f[l][r] = w;
    }

    for( int len = 1; len <= n; ++ len )
    {
        // int cur = len & 1;
        // int pre = ( len - 1 ) & 1;
        for( int i = 1; i + len - 1 <= n; ++ i )
        {
            int j = i + len - 1;
            for( int k = i; k <= j; ++ k )
            {
                long long res = f[i][j];
                if( k >= i + 1 ) res = max( res, g[i+1][j][k] );
                if( k <= j - 1 ) res = max( res, g[i][j-1][k] );
                g[i][j][k] = res;
            }

            for( int k = i; k <= j; ++ k )
            {
                long long res = g[i][j][k];
                if( k > i ) res += dp[i][k-1];
                if( k < j ) res += dp[k+1][j];
                dp[i][j] = max( dp[i][j], res );
            }
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}