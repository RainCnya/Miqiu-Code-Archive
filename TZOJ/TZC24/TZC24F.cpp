#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const ll inf = 1e18;

ll dp[4][maxn];
ll a[4][maxn];
int n;

ll _max( ll a, ll b, ll c )
{
    return max( a, max( b, c ) );
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= 3; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            cin >> a[i][j];
            dp[i][j] = -inf;
        }
    }

    dp[1][1] = a[1][1];
    dp[2][1] = a[1][1] + a[2][1] - 1;
    dp[3][1] = a[1][1] + a[2][1] + a[3][1] - 2;

    for( int j = 2; j <= n; ++ j )
    {
        ll from1 = dp[1][j-1] + a[1][j]; 
        ll from2 = dp[2][j-1] + a[2][j] + a[1][j] - 1;
        ll from3 = dp[3][j-1] + a[3][j] + a[2][j] + a[1][j] - 2;
        dp[1][j] = max({from1, from2, from3});

        from1 = dp[1][j-1] + a[1][j] + a[2][j] - 1;
        from2 = dp[2][j-1] + a[2][j];
        from3 = dp[3][j-1] + a[3][j] + a[2][j] - 1;
        dp[2][j] = max({from1, from2, from3});

        from1 = dp[1][j-1] + a[1][j] + a[2][j] + a[3][j] - 2;
        from2 = dp[2][j-1] + a[2][j] + a[3][j] - 1;
        from3 = dp[3][j-1] + a[3][j];
        dp[3][j] = max({from1, from2, from3});
    }

    ll ans = -inf;
    for( int i = 1; i <= 3; ++ i )
    {
        for( int j= 1; j <= n; ++ j )
        {
            ans = max( ans, dp[i][j] );
        }
    }
    cout << ans << '\n';
    return 0;
}