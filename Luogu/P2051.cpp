#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int mod = 9999973;

long long dp[maxn][maxn][maxn];
int n, m;

void calc( int i, int j, int k, long long add ) {
    dp[i][j][k] = ( dp[i][j][k] + add ) % mod;
}

long long c2( int x ) {
    return x * (x - 1) / 2;
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    dp[0][0][0] = 1;

    for( int i = 0; i < n; ++ i )
    {
        for( int j = 0; j <= m; ++ j )
        {
            for( int k = 0; k + j <= m; ++ k )
            {
                if( !dp[i][j][k] ) continue;
                long long cur = dp[i][j][k];
                int z = m - j - k;
                
                calc( i+1, j, k, cur );

                if( z >= 1 ) {
                    calc( i+1, j+1, k, cur * z );
                }
                if( j >= 1 ) {
                    calc( i+1, j-1, k+1, cur * j );
                }
                if( z >= 2 ) {
                    calc( i+1, j+2, k, cur * c2( z ) );
                }
                if( j >= 2 ) {
                    calc( i+1, j-2, k+2, cur * c2( j ) );
                }
                if( j >= 1 && z >= 1 ) {
                    calc( i+1, j, k+1, cur * z * j );
                }
            }
        }
    }

    long long ans = 0;
    for( int j = 0; j <= m; ++ j )
    {
        for( int k = 0; k + j <= m; ++ k )
        {
            ans = ( ans + dp[n][j][k] ) % mod;
        }
    }

    cout << ans << '\n';
    return 0;
}