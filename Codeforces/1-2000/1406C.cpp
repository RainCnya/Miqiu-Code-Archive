#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

vector< int > adj[maxn];
int siz[maxn];
int f[maxn];
int n;

void dfs( int u, int fa )
{
    siz[u] = 1;
    f[u] = 0;

    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        dfs( v, u );
        siz[u] += siz[v];
        f[u] = max( f[u], siz[v] );
    }
    f[u] = max( f[u], n - siz[u] );
}

void find_leaf( int u, int fa, int &leaf, int &leaf_fa )
{
    bool is_leaf = 1;
    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        is_leaf = 0;
        find_leaf( v, u, leaf, leaf_fa );
    }
    if( is_leaf )
    {
        leaf = u;
        leaf_fa = fa;
    }
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) 
    {
        f[i] = inf;
        adj[i].clear( );
    }

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    dfs( 1, 0 );

    int min_val = inf;
    int root1 = -1, root2 = -1;

    for( int i = 1; i <= n; ++ i )
    {
        if( f[i] < min_val )
        {
            min_val = f[i];
            root1 = i;
            root2 = -1;
        }
        else if( f[i] == min_val )
        {
            root2 = i;
        }
    }

    if( root2 == -1 )
    {
        int u = 1, v = adj[u][0];
        cout << u << " " << v << '\n';
        cout << u << " " << v << '\n';
    }
    else
    {
        int leaf = -1, leaf_fa = -1;
        find_leaf( root1, root2, leaf, leaf_fa );
        cout << leaf << " " << leaf_fa << '\n';
        cout << leaf << " " << root2 << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
