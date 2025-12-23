#include<bits/stdc++.h>
using namespace std;

const int maxn = 60;

int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];

int main()
{	
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> a[i][j];
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            for( int k = 1; k <= n; ++ k )
            {
                for( int l = 1; l <= m; ++ l )
                {
                    int mx1 = max( dp[i-1][j][k-1][l], dp[i-1][j][k][l-1] );
                    int mx2 = max( dp[i][j-1][k-1][l], dp[i][j-1][k][l-1] );
                    int mx = max( mx1, mx2 );
                    dp[i][j][k][l] = mx + a[i][j] + a[k][l];
                    if( i == k && j == l )
                    {
                        dp[i][j][k][l] -= a[i][j];
                    }
                }
            }
        }
    }
    
    cout << dp[n][m][n][m];
    return 0;
}