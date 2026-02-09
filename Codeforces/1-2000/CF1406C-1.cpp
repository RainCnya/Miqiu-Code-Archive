#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

vector< int > adj[maxn];
int sz[maxn], f[maxn];
int r1, r2;
int n;

int leaf, leaf_p;

void find_leaf( int u, int p )
{
    if( adj[u].size( ) == 1 ) 
    {
        leaf = u;
        leaf_p = p;
        return;
    }
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        find_leaf( v, u );
        if( leaf != -1 ) return;
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
    if( f[u] < f[r1] ) r1 = u, r2 = 0;
    else if( f[u] == f[r1] ) r2 = u;
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) adj[i].clear( );
    r1 = r2 = 0;
    f[0] = n + 1;

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    get_root( 1, 0 );

    if( r2 == 0 ) 
    {
        cout << adj[r1][0] << ' ' << r1 << '\n';
        cout << adj[r1][0] << ' ' << r1 << '\n';
    }
    else
    {
        leaf = -1;
        find_leaf( r1, r2 );

        cout << leaf << ' ' << leaf_p << '\n';
        cout << leaf << ' ' << r2 << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}