#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

vector< int > adj[maxn];
int dist[maxn], fa[maxn];
int dep[maxn];
int n, k, ed;

void dfs( int u, int p, int d )
{
    dist[u] = d;
    fa[u] = p;
    if( dist[u] > dist[ed] ) ed = u;
    for( int v : adj[u] ) if( v != p ) dfs( v, u, d + 1 );
}

void dfs1( int u, int p )
{
    dep[u] = 0;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs1( v, u );
        dep[u] = max( dep[u], dep[v] + 1 );
    }
}

bool check( int mid )
{
    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( dep[i] >= mid ) cnt ++;
    }
    return cnt <= k;
}

void solve( )
{
    cin >> n >> k;
    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    ed = 0, dist[0] = -1;
    dfs( 1, 0, 0 );
    int u = ed;
    ed = 0, dist[0] = -1;
    dfs( u, 0, 0 );
    int v = ed;

    vector< int > paths;
    for( int cur = v; cur != 0; cur = fa[cur] )
    {
        paths.push_back( cur );
    }
    int pos = paths[paths.size( ) / 2];

    dfs1( pos, 0 );

    int l = 0, r = n, ans = n;
    while( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if( check( mid ) ) ans = mid, r = mid - 1;
        else l = mid + 1;
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