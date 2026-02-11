#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;
const int maxlg = 20;

struct Edge { int v, w; };
vector<Edge> adj[maxn];

int up[maxn][maxlg], dep[maxn];
int dist[maxn], edgew[maxn];

struct Path { int u, v, lca, len; } p[maxn];
int diff[maxn], sum[maxn];
int max_len, max_edge, max_weight;
int n, m;

int read( )
{
    int x = 0, f = 1;
    char ch = getchar( );
    while( ch < '0' || ch > '9' ) { if( ch == '-' ) f = -1; ch = getchar( ); }
    while( ch >= '0' && ch <= '9' ) { x = x * 10 + ch - '0'; ch = getchar( ); }
    return x * f;
}

void dfs( int u, int p, int w )
{
    dep[u] = dep[p] + 1;
    up[u][0] = p;
    dist[u] = dist[p] + w;
    edgew[u] = w;

    for( int i = 1; i < maxlg; ++ i )
        up[u][i] = up[up[u][i - 1]][i - 1];

    for( auto &[v, w] : adj[u] )
        if( v != p ) dfs( v, u, w );
}

int get_lca( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = 0; i < maxlg; ++ i )
        if( ( diff >> i ) & 1 ) u = up[u][i];
    if( u == v ) return u;
    for( int i = maxlg - 1; i >= 0; -- i )
        if( up[u][i] != up[v][i] )
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

void dfs_sum( int u, int p, int cnt )
{
    sum[u] = diff[u];
    for( auto &[v, w] : adj[u] )
        if( v != p ) dfs_sum( v, u, cnt ), sum[u] += sum[v];
    if( sum[u] == cnt ) max_edge = max( max_edge, edgew[u] );
}

bool check( int mid )
{
    int cnt = 0;
    for( int i = 1; i <= n; ++ i ) diff[i] = 0;

    for( int i = 1; i <= m; ++ i )
    {
        if( p[i].len <= mid ) continue;
        cnt ++;
        diff[p[i].u] ++, diff[p[i].v] ++;
        diff[p[i].lca] -= 2;
    }
    if( cnt == 0 ) return 1;

    max_edge = 0;
    dfs_sum( 1, 0, cnt );
    
    return max_len - max_edge <= mid;
}

void solve( )
{
    n = read( ), m = read( );
    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v, w;
        u = read( ), v = read( ), w = read( );
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
        max_weight = max( max_weight, w );
    }

    dfs( 1, 0, 0 );

    for( int i = 1; i <= m; ++ i )
    {
        p[i].u = read( ), p[i].v = read( );
        p[i].lca = get_lca( p[i].u, p[i].v );
        p[i].len = dist[p[i].u] + dist[p[i].v] - 2 * dist[p[i].lca];
        max_len = max( max_len, p[i].len );
    }

    int l = max( 0, max_len - max_weight ), r = max_len, ans = max_len;
    while( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if( check( mid ) ) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << '\n';
    return ;
}

int main( )
{
    // ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}