#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
const int inf = 1e9;

int dp[maxn][7];
int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int j = 1; j <= 6; ++ j )
    {
        if( a[1] == j ) dp[1][j] = 0;
        else dp[1][j] = inf;
    }

    for( int i = 2; i <= n; ++ i )
    {
        for( int j = 1; j <= 6; ++ j )
        {
            dp[i][j] = inf;
            int cost = 1;
            if( a[i] == j ) cost = 0;

            for( int k = 1; k <= 6; ++ k )
            {
                if( j == k || j + k == 7 ) continue;
                dp[i][j] = min( dp[i][j], dp[i - 1][k] + cost );
            }
        }
    }

    int ans = inf;
    for( int j = 1; j <= 6; ++ j ) ans = min( ans, dp[n][j] );
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}