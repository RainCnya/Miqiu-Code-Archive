#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

vector< int > adj[maxn];
int n, m;
int a[maxn];
int sz[maxn];
int fa[maxn];

void dfs( int u, int p )
{
    fa[u] = p;
    sz[u] = 1;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
        sz[u] += sz[v];
    }
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) a[i] = 1;
    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }
    dfs( 1, 0 );
    cin >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int x;
        char op; cin >> op >> x;
        if( op == 'Q' ) 
        {
            cout << sz[x] << '\n';
        } 
        else 
        {
            if( a[x] == 0 ) 
            {
                a[x] = 1;
                for( int u = x; u != 0; u = fa[u] )  sz[u] ++;
            }
            else
            {
                a[x] = 0;
                for( int u = x; u != 0; u = fa[u] )  sz[u] --;
            }
        }
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}