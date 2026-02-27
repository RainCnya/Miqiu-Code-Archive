#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;
const int inf = 0x3f3f3f3f;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
int dp[maxn][maxn];
// dp[u][j] 表示在 u 的子树中选 j 个点的最大收益
int sz[maxn];
int money[maxn];
int n, m;

void dfs( int u, int p )
{
    for( int j = 0; j <= m; ++ j ) dp[u][j] = -inf;
    dp[u][0] = 0;

    if( u > n - m )
    {
        dp[u][1] = money[u];
        sz[u] = 1;
        return;
    }

    int tot = 0;
    for( auto [v, w] : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
        tot += sz[v];

        for( int j = tot; j >= 1; -- j )
        {
            for( int k = 1; k <= j && k <= sz[v]; ++ k )
            {
                if( dp[u][j - k] == -inf || dp[v][k] == -inf ) continue;
                dp[u][j] = max( dp[u][j], dp[u][j - k] + dp[v][k] - w );
            }
        }
        sz[u] = tot;
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= n - m; ++ i )
    {
        int k, v, w;
        cin >> k;
        for( int j = 1; j <= k; ++ j )
        {
            cin >> v >> w;
            adj[i].push_back({ v, w });
        }
    }

    for( int i = n - m + 1; i <= n; ++ i ) cin >> money[i];

    dfs( 1, 0 );

    for( int j = m; j >= 1; -- j )
    {
        if( dp[1][j] >= 0 )
        {
            cout << j << '\n';
            break;
        }
    }
    return 0;
}