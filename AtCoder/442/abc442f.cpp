#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 5e3 + 50;
const ll inf = 1e18;

char g[maxn][maxn];
ll dp[maxn][maxn];
ll sum[maxn][maxn];
ll tmp[maxn];
int n;

ll get_cost( int i, int j )
{
    ll cnt1 = sum[i][j];
    ll cnt2 = ( n - j ) - ( sum[i][n] - sum[i][j] );
    return cnt1 + cnt2;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            cin >> g[i][j];
            sum[i][j] = sum[i][j-1];
            if( g[i][j] == '#' ) sum[i][j] ++;
        }
    }

    for( int j = 0; j <= n; ++ j ) 
    {
        dp[0][j] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        tmp[n] = dp[i-1][n];
        for( int j = n - 1; j >= 0; -- j )
        {
            tmp[j] = min( tmp[j+1], dp[i-1][j] );
        }
        
        for( int j = 0; j <= n; ++ j )
        {
            dp[i][j] = tmp[j] + get_cost( i, j );
        }
    }

    ll ans = inf;
    for( int j = 0; j <= n; ++ j )
    {
        ans = min( ans, dp[n][j] );
    }
    cout << ans << "\n";

    return 0;
}