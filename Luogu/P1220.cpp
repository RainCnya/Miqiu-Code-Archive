#include<bits/stdc++.h>
using namespace std;

const int maxn = 55;

long long dp[maxn][maxn][2];
long long sum[maxn];
int p[maxn], w[maxn];
int n, c;

int main( )
{	
    cin >> n >> c;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> p[i] >> w[i];
        sum[i] = sum[i-1] + w[i];
    }

    memset( dp, 127, sizeof( dp ) );
    dp[c][c][0] = dp[c][c][1] = 0;

    for( int len = 2; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;
            
            int lcost = sum[l] + sum[n] - sum[r];
            // [l+1,r] --> [1,l]/[r+1,n]
            dp[l][r][0] = min( dp[l][r][0], dp[l+1][r][0] + (p[l+1] - p[l]) * lcost );
            dp[l][r][0] = min( dp[l][r][0], dp[l+1][r][1] + (p[r] - p[l]) * lcost );   

            int rcost = sum[l-1] + sum[n] - sum[r-1];
            // [l,r-1] --> [1,l-1]/[r.n]
            dp[l][r][1] = min( dp[l][r][1], dp[l][r-1][0] + (p[r] - p[l]) * rcost );
            dp[l][r][1] = min( dp[l][r][1], dp[l][r-1][1] + (p[r] - p[r-1]) * rcost );
        }
    }

    cout << min( dp[1][n][0], dp[1][n][1] ) << '\n';
    return 0;
}