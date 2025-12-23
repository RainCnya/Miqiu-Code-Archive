#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e3 + 50;

int dp[maxn][maxn];
int c[30];
int n, m;

int main()
{	
    cin >> m >> n;
    string s;
    cin >> s;
    s = ' ' + s;

    for( int i = 1; i <= m; ++ i )
    {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        c[ ch - 'a' ] = min( a, b );
    }

    memset( dp, 127, sizeof( dp ) );

    for( int i = 1; i <= n; ++ i )
    {
        dp[i][i] = 0;
        dp[i][i-1] = 0;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;
            if( s[l] == s[r] )
                dp[l][r] = min( dp[l][r], dp[l+1][r-1] );

            dp[l][r] = min( dp[l][r], dp[l+1][r] + c[ s[l] - 'a' ] );
            dp[l][r] = min( dp[l][r], dp[l][r-1] + c[ s[r] - 'a' ] );
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}