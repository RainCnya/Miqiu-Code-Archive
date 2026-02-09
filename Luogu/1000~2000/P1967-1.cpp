#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;
const int maxm = 5e4 + 50;
const int maxlg = 20;
const int inf = 0x3f3f3f3f;

struct Edge { int u, v, w; } edges[maxm];
struct Node { int v, w; };
vector< Node > adj[maxn];
int fa[maxn], dep[maxn];
int up[maxn][maxlg];
int min_w[maxn][maxlg];
bool vis[maxn];
int n, m, q;

bool cmp( const Edge &lhs, const Edge &rhs ) { return lhs.w > rhs.w; }

int find( int x ) { return fa[x] == x ? x : fa[x] = find( fa[x] ); }

void dfs( int u, int p, int w )
{
    vis[u] = 1;
    dep[u] = dep[p] + 1;
    up[u][0] = p;
    min_w[u][0] = w;

    for( int i = 1; i < maxlg; ++ i )
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
        min_w[u][i] = min( min_w[u][i - 1], min_w[up[u][i - 1]][i - 1] );
    }
    
    for( auto [v, w] : adj[u] )
    {
        if( v != p ) dfs( v, u, w );
    }
}

int query( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    int res = inf;

    for( int i = 0; i < maxlg; ++ i )
    {
        if( ( diff >> i ) & 1 )
        {
            res = min( res, min_w[u][i] );
            u = up[u][i];
        }
    }

    if( u == v ) return res;
    
    for( int i = maxlg - 1; i >= 0; -- i )
    {
        if( up[u][i] != up[v][i] )
        {
            res = min( res, min_w[u][i] );
            res = min( res, min_w[v][i] );
            u = up[u][i];
            v = up[v][i];
        }
    }

    res = min( res, min_w[u][0] );
    res = min( res, min_w[v][0] );
    return res;
}


void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }
    sort( edges + 1, edges + m + 1, cmp );

    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    
    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w] = edges[i];
        int ru = find( u ), rv = find( v );
        if( ru != rv )
        {
            fa[ru] = rv;
            adj[ru].push_back( { rv, w } );
            adj[rv].push_back( { ru, w } );
        }
    }

    memset( min_w, 0x3f, sizeof (min_w) );
    for( int i = 1; i <= n; ++ i )
    {
        if( !vis[i] ) dfs( i, 0, 0 );
    }
    
    cin >> q;
    while( q -- )
    {
        int u, v;
        cin >> u >> v;
        if( find( u ) != find( v ) ) cout << -1 << '\n';
        else cout << query( u, v ) << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}