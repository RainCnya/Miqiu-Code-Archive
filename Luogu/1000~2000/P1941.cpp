#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 50;
const int maxm = 2e3 + 50;
const int inf = 0x3f3f3f3f;

bool flag[maxn];
int l[maxn], h[maxn];
int x[maxn], y[maxn];
int dp[2][maxm];
int n, m, k;

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> k;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> x[i] >> y[i];
        l[i] = 0;
        h[i] = m + 1;
        flag[i] = 0;
    }

    for( int i = 1; i <= k; ++ i )
    {
        int p, _l, _h;
        cin >> p >> _l >> _h;
        l[p] = _l, h[p] = _h;
        flag[p] = 1;
    }
    
    memset( dp, 0x3f, sizeof( dp ) );

    for( int j = 1; j <= m; ++ j )
    {
        dp[0][j] = 0;
    }

    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int cur = i & 1;
        int pre = (i - 1) & 1;

        for( int j = 1; j <= m; ++ j )
        {
            dp[cur][j] = inf;
        }

        for( int j = x[i] + 1; j <= m; ++ j )
        {
            dp[cur][j] = min( dp[cur][j], dp[pre][j - x[i]] + 1 );
            dp[cur][j] = min( dp[cur][j], dp[cur][j - x[i]] + 1 );
        }

        for( int j = m - x[i]; j <= m; ++ j )
        {
            dp[cur][m] = min( dp[cur][m], dp[cur][j] + 1 );
            dp[cur][m] = min( dp[cur][m], dp[pre][j] + 1 );
        }

        for( int j = 1; j <= m; ++ j )
        {
            dp[cur][j] = min( dp[cur][j], dp[pre][j + y[i]] );
        }

        for( int j = 1; j <= l[i]; ++ j ) dp[cur][j] = inf;
        for( int j = h[i]; j <= m; ++ j ) dp[cur][j] = inf;

        int mn = inf;
        for( int j = 1; j <= m; ++ j )
        {
            mn = min( mn, dp[cur][j] );
        }
        
        if( mn == inf )
        {
            cout << 0 << '\n';
            cout << cnt << '\n';
            return 0;
        }

        if( flag[i] )
        {
            cnt ++;
        }
    }

    int ans = inf;
    for( int j = 1; j <= m; ++ j )
    {
        ans = min( ans, dp[n&1][j] );
    }

    cout << 1 << '\n';
    cout << ans << '\n';

    return 0;
}