#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;
const int inf = 0x3f3f3f3f;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
int dist[maxn], fa[maxn], sz[maxn];
int disu[maxn], disv[maxn];
bool on_path[maxn];
int n, s, max_dist, ed;

void dfs( int u, int p, int d )
{
    dist[u] = d;
    fa[u] = p;

    if( d > max_dist ) max_dist = d, ed = u;

    for( auto [v, w] : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u, d + w );
    }
}

int dfs_branch( int u, int p )
{
    int res = 0;
    for( auto [v, w] : adj[u] )
    {
        if( v == p || on_path[v] ) continue;
        res = max( res, dfs_branch( v, u ) + w );
    }
    return res;
}

void solve( )
{
    cin >> n >> s;

    for( int i = 1; i < n; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    max_dist = 0; 
    dfs( 1, 0, 0 );
    int u = ed;
    max_dist = 0; 
    dfs( u, 0, 0 );
    int v = ed;

    vector< int > paths;
    for( int cur = v; cur != 0; cur = fa[cur] )
    {
        on_path[cur] = true;
        paths.push_back( cur );
    }
    reverse( paths.begin( ), paths.end( ) );

    int max_branch = 0;
    for( int cur : paths ) max_branch = max( max_branch, dfs_branch( cur, 0 ) );

    int ans = inf;
    int m = paths.size( );

    for( int k = 0; k < m; ++ k )
    {
        disu[k] = dist[paths[k]];
        disv[k] = dist[v] - disu[k];
    }

    for( int i = 0, j = 0; i < m; ++ i )
    {
        while( j + 1 < m && disu[j + 1] - disu[i] <= s ) j ++;
        int ecc = max( max_branch, max( disu[i], disv[j] ) );
        ans = min( ans, ecc );
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}