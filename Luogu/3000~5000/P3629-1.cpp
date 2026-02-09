#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

struct Pre { int p, idx; } pre[maxn];

struct Edge { int v, w, rev; };
vector< Edge > adj[maxn];

int dist[maxn], from_node[maxn], from_edge[maxn];
int L1, L2, ed;
int dp[maxn];
int n, k;

void add_edge( int u, int v, int w )
{
    int idx_u = adj[u].size( );
    int idx_v = adj[v].size( );
    adj[u].push_back({ v, w, idx_v });
    adj[v].push_back({ u, w, idx_u });
}

void dfs( int u, int p, int d )
{
    dist[u] = d;
    if( d > L1 ) L1 = d, ed = u;

    for( int i = 0; i < adj[u].size( ); ++ i )
    {
        int v = adj[u][i].v;
        if( v == p ) continue;
        pre[v] = { u, i };
        dfs( v, u, d + 1 );
    }
}

void dfs_dp( int u, int p )
{
    dp[u] = 0;
    for( auto &e : adj[u] )
    {
        if( e.v == p ) continue;
        dfs_dp( e.v, u );
        L2 = max( L2, dp[u] + dp[e.v] + e.w );
        dp[u] = max( dp[u], dp[e.v] + e.w );
    }
}

void solve( )
{
    cin >> n >> k;
    for (int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        add_edge( u, v, 1 );
    }

    L1 = -1;
    dfs( 1, 0, 0 );
    int u = ed;

    L1 = -1;
    dfs( u, 0, 0 );
    int v = ed;

    int cost = 2 * ( n - 1 ) - ( L1 - 1 );

    if( k == 1 )
    {
        cout << cost << '\n';
        return ;
    }

    for( int cur = v; cur != u; cur = pre[cur].p )
    {
        auto [p, idx] = pre[cur];
        adj[p][idx].w = -1;

        int r_idx = adj[p][idx].rev;
        adj[cur][r_idx].w = -1;
    }

    L2 = 0;
    dfs_dp( 1, 0 );
    cout << cost - ( L2 - 1 ) << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}