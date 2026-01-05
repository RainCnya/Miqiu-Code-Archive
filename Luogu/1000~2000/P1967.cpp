#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e4 + 50;
const int maxm = 1e5 + 50;
const int inf = 0x3f3f3f3f;

struct Edge {
    int u, v, w;

    bool operator <( const Edge &other ) const {
        return w > other.w;
    }
} edges[maxm];

int fa[maxn];
int f[maxn][20];
int min_w[maxn][20];
int dep[maxn];
bool vis[maxn];
vector<PII> adj[maxn];
int n, m, q;

int find( int x )
{
    if( x == fa[x] ) return fa[x];
    else return fa[x] = find( fa[x] );
}

bool kruskal( )
{
    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    sort( edges + 1, edges + m + 1 );

    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w] = edges[i];
        int ru = find( u ), rv = find( v );
        if( ru != rv )
        {
            fa[ru] = rv;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }
    return true;
}

void dfs( int u, int father, int w )
{
    vis[u] = 1;
    dep[u] = dep[father] + 1;

    f[u][0] = father;
    min_w[u][0] = w;

    for( int i = 1; i < 20; ++ i )
    {
        f[u][i] = f[ f[u][i-1] ][i-1];
        min_w[u][i] = min( min_w[u][i-1], min_w[ f[u][i-1] ][i-1] );
    }
    for( auto [v, val] : adj[u] )
    {
        if( v != father ) dfs( v, u, val );
    }
}

int query( int x, int y )
{
    int ans = inf;
    if( dep[x] < dep[y] ) swap( x, y );
    for( int i = 19; i >= 0; -- i )
    {
        if( dep[f[x][i]] >= dep[y] )
        {
            ans = min( ans, min_w[x][i] );
            x = f[x][i];
        }
    }
    if( x == y ) return ans;

    for( int i = 19; i >= 0; -- i )
    {
        if( f[x][i] != f[y][i] )
        {
            ans = min( ans, min_w[x][i] );
            ans = min( ans, min_w[y][i] );
            x = f[x][i];
            y = f[y][i];
        }
    }
    ans = min( ans, min_w[x][0] );
    ans = min( ans, min_w[y][0] );
    return ans;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    kruskal( );

    memset( min_w, 0x3f, sizeof( min_w ) );
    
    for( int i = 1; i <= n; ++ i )
    {
        if( !vis[i] ) dfs( i, 0, inf );
    }

    cin >> q;
    for( int i = 1; i <= q; ++ i )
    {
        int x, y;
        cin >> x >> y;
        if( find( x ) != find( y ) )
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << query( x, y ) << '\n';
        }
    }
    return 0;
}