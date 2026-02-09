#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int maxlg = 20;

struct Edge { 
    int u, v, w, id; 
    bool operator < ( const Edge &oth ) const { return w < oth.w; }
} edges[maxn], ori_edges[maxn];

struct Node { int u, w; };
vector< Node > adj[maxn];

int dep[maxn];
int fa_mst[maxn];
int fa[maxn][maxlg];
ll max_w[maxn][maxlg];
ll mst_weight;
int n, m;

int find( int x )
{
    if( fa_mst[x] == x ) return fa_mst[x];
    return fa_mst[x] = find( fa_mst[x] );
}

void kruskal( )
{
    for( int i = 1; i <= n; ++ i ) fa_mst[i] = i;
    sort( edges + 1, edges + m + 1 );

    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w, id] = edges[i];
        int ru = find( u ), rv = find( v );

        if( ru != rv )
        {
            fa_mst[ru] = rv;
            mst_weight += w;
            adj[u].push_back({ v, w });
            adj[v].push_back({ u, w });
        }
    }
}

void dfs( int u, int p, ll w )
{
    fa[u][0] = p;
    max_w[u][0] = w;
    dep[u] = dep[p] + 1;
    for( auto [v, w] : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u, w );
    }
}

void init( )
{
    for( int j = 1; j < maxlg; ++ j )
    {
        for( int i = 1; i <= n; ++ i )
        {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            max_w[i][j] = max( max_w[i][j - 1], max_w[fa[i][j - 1]][j - 1] );
        }
    }
}

ll query( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );

    ll res = 0;
    int diff = dep[u] - dep[v];

    for( int i = 0; i < maxlg; ++ i )
    {
        if( ( diff >> i ) & 1 )
        {
            res = max( res, max_w[u][i] );
            u = fa[u][i];
        }
    }

    if( u == v ) return res;
    
    for( int i = maxlg - 1; i >= 0; -- i )
    {
        if( fa[u][i] != fa[v][i] )
        {
            res = max( res, max_w[u][i] );
            res = max( res, max_w[v][i] );
            u = fa[u][i];
            v = fa[v][i];
        }
    }

    res = max( res, max_w[u][0] );
    res = max( res, max_w[v][0] );

    return res;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { u, v, w, i };
        ori_edges[i] = edges[i];
    }

    kruskal( );
    dfs( 1, 0, 0 );
    init( );

    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w, id] = ori_edges[i];
        cout << mst_weight + w - query( u, v ) << '\n';
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}