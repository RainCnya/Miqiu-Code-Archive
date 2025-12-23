#include<bits/stdc++.h>
using namespace std;

const int maxn = 15;

int a[maxn][maxn];
int dp[maxn][maxn][maxn][maxn];
int n, m;

int main()
{	
    cin >> n;
    int x, y, v;
    while( cin >> x >> y >> v )
    {
        if( x == 0 && y == 0 && v == 0 ) break;
        a[x][y] = v;
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            for( int k = 1; k <= n; ++ k )
            {
                for( int l = 1; l <= n; ++ l )
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
    
    cout << dp[n][n][n][n];
    return 0;
}