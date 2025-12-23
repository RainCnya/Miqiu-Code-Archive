#include<bits/stdc++.h>
using namespace std;

const int maxn = 55;
const int inf = 1e9;

int dp[maxn][maxn];
string s;
int n;

int main()
{	
    cin >> s;
    n = s.length( );
    s = ' ' + s;

    memset( dp, 127, sizeof( dp ) );

    for( int i = 1; i <= n; ++ i )
    {
        dp[i][i] = 1;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;
            if( s[l] == s[r] )
            {
                dp[l][r] = min( dp[l+1][r], dp[l][r-1] );
            }
            else
            {
                for( int k = l; k < r; ++ k )
                {
                    dp[l][r] = min( dp[l][r], dp[l][k] + dp[k+1][r] );
                }
            }
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}