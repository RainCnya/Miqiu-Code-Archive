#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 5;

vector< int > adj[maxn];
int s[maxn];
ll dp[maxn][maxn];
// dp[u][i] 表示以 u 为根的子树中，选 i 个点的最大价值
int n, m;

void dfs( int u )
{
    dp[u][1] = s[u];

    for( int v : adj[u] )
    {
        dfs( v );
        
        for( int i = m + 1; i >= 1; -- i )
        {
            for( int j = 0; j < i; ++ j )
            {
                dp[u][i] = max( dp[u][i], dp[u][i - j] + dp[v][j] );
            }
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) 
    {
        int k;
        cin >> k >> s[i];
        adj[k].push_back( i );
    }

    dfs( 0 );
    cout << dp[0][m + 1] << '\n';
    return 0;
}