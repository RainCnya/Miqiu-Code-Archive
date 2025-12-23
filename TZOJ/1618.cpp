#include<bits/stdc++.h>
using namespace std;

const int maxn = 350 + 50;
const int inf = 1e9;

int a[maxn][maxn];
int dp[maxn][maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= i; ++ j )
        {
            cin >> a[i][j];
        }
    }

    memset( dp, 0, sizeof( dp ) );
    dp[1][1] = a[1][1];
    
    for( int i = 2; i <= n; ++ i )
    {
        for( int j = 1; j <= i; ++ j )
        {
            if( j == 1 ) dp[i][j] = dp[i-1][j] + a[i][j];
            else if( j == i ) dp[i][j] = dp[i-1][j-1] + a[i][j];
            else dp[i][j] = max( dp[i-1][j], dp[i-1][j-1] ) + a[i][j];
        }
    }

    int ans = 0;
    for( int j = 1; j <= n; ++ j )
    {
        ans = max( ans, dp[n][j] );
    }

    cout << ans << '\n';
    return 0;
}