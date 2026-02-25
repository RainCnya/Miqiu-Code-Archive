#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
int val[maxn];
ll f[maxn][maxn];
// f[u][i] 以 u 为根的子树中，选 i 个节点的最大价值
int n, q;

void dfs( int u, int p )
{
    int l = 0, r = 0;
    for( auto [v, w] : adj[u] )
    {
        if( v == p ) continue;
        val[v] = w;
        if( l == 0 ) l = v;
        else r = v;
        dfs( v, u );
    }
 
    if( l == 0 && r == 0 ) 
    {
        f[u][1] = val[u];
        return;
    }

    for( int j = 1; j <= n; ++ j )
    {   // 当前子树总共 j 个点
        for( int k = 0; k <= j - 1; ++ k )
        {   // 左边 k 个，右边 j-k-1 个
            f[u][j] = max( f[u][j], f[l][k] + f[r][j-k-1] + val[u] );
        }
    }
}

int main( )
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    
    cin >> n >> q;

    for( int i = 1; i < n; ++ i )
    {
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dfs( 1, 0 );

    cout << f[1][q + 1] << '\n';
    return 0;
}