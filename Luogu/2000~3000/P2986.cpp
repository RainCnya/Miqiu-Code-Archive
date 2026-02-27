#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const ll inf = 1e18;

struct Edge { int v, w; };

vector< Edge > adj[maxn];
ll f[maxn];
// f 子树贡献
ll ans[maxn];
ll sz[maxn];
ll val[maxn];
int total = 0;
int n;

void dfs1( int u, int p )
{
    sz[u] = val[u];
    f[u] = 0;
    for( auto [v, w] : adj[u] )
    {
        if( v == p ) continue;
        dfs1( v, u );
        sz[u] += sz[v];
        f[u] += f[v] + sz[v] * w;
    }
}

void dfs2( int u, int p )
{
    for( auto [v, w] : adj[u] )
    {
        if( v == p ) continue;
        ans[v] = ans[u] + ( total - sz[v] ) * w - sz[v] * w;
        dfs2( v, u );
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> val[i];
        total += val[i];
    }

    for( int i = 1; i < n; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs1( 1, 0 );
    ans[1] = f[1];
    dfs2( 1, 0 );

    ll res = inf;
    for( int i = 1; i <= n; ++ i ) res = min( res, ans[i] );
    cout << res << '\n';

    return 0;
}