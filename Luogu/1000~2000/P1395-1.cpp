#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;

vector< int > adj[maxn];

int sz[maxn];
int f[maxn];
int dep[maxn];
int root;
int n;

void dfs( int u, int p )
{
    dep[u] = dep[p] + 1;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
    }
}

void get_root( int u, int p )
{
    sz[u] = 1;
    f[u] = 0;

    for( int v : adj[u] )
    {
        if( v == p ) continue;
        get_root( v, u );
        sz[u] += sz[v];
        f[u] = max( f[u], sz[v] );
    }

    f[u] = max( f[u], n - sz[u] );
    if( root == 0 || f[u] < f[root] ) root = u;
    if( f[u] == f[root] ) root = min( root, u );
}

void solve( )
{
    cin >> n;
    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    get_root( 1, 0 );
    cout << root << ' ';

    dep[0] = -1;
    dfs( root, 0 );
    int ans = 0;

    for( int i = 1; i <= n; ++ i ) ans += dep[i];
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}