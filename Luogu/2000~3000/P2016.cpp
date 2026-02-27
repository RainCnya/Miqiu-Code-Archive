#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1500 + 5;

vector< int > adj[maxn];
int a[maxn];
int dp[maxn][2];
// 0 不选 / 1 选
int n;

void dfs( int u, int p )
{
    dp[u][1] = 1, dp[u][0] = 0;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
        dp[u][0] += dp[v][1];
        dp[u][1] += min( dp[v][0], dp[v][1] );
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        int u, k, v;
        cin >> u >> k;
        for( int j = 1; j <= k; ++ j )
        {
            cin >> v;
            adj[u].push_back( v );
            adj[v].push_back( u );
        }
    }

    dfs( 0, 0 );

    cout << min( dp[0][0], dp[0][1] ) << '\n';
    return 0;
}