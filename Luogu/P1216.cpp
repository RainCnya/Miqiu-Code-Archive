#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 50;

int dp[maxn][maxn];
int r;

int main( )
{	
    cin >> r;
    for( int i = 1; i <= r; ++ i )
    {
        for( int j = 1; j <= i; ++ j )
        {
            cin >> dp[i][j];
        }
    }

    for( int i = 1; i <= r; ++ i )
    {
        for( int j = 1; j <= i; ++ j )
        {
            if( j == 1 ) dp[i][j] += dp[i-1][j];
            else if( j == i ) dp[i][j] += dp[i-1][j-1] ;
            else dp[i][j] += max( dp[i-1][j], dp[i-1][j-1] );
        }
    }
    
    int ans = 0;
    for( int j = 1; j <= r; ++ j )
    {
        ans = max( ans, dp[r][j] );
    }
    
    cout << ans << '\n';
    return 0;
}