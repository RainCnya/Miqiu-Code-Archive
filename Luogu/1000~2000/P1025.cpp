#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 50;

int dp[maxn][maxn];
int n, k;

int main()
{	
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i )
    {
        dp[i][1] = 1;
    }
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 2; j <= k; ++ j )
        {
            if( i >= j )
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
        }
    }
    cout << dp[n][k];
    return 0;
}