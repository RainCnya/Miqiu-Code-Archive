#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int mod = 19650827;

int dp[maxn][maxn][2];
int h[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> h[i];
    }

    for( int i = 1; i <= n; ++ i )
    {
        dp[i][i][0] = 1;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;

            if( h[l] < h[l+1] )
                dp[l][r][0] = ( dp[l][r][0] + dp[l+1][r][0] ) % mod;
            if( h[l] < h[r] )
                dp[l][r][0] = ( dp[l][r][0] + dp[l+1][r][1] ) % mod;
            
            if( h[r] > h[l] )
                dp[l][r][1] = ( dp[l][r][1] + dp[l][r-1][0] ) % mod;
            if( h[r] > h[r-1] )
                dp[l][r][1] = ( dp[l][r][1] + dp[l][r-1][1] ) % mod;
        }
    }

    cout << ( dp[1][n][0] + dp[1][n][1] ) % mod << '\n';
    return 0;
}