#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e4 + 50;

vector< int > adj[maxn];
int dfn[maxn], low[maxn], timer;
bool is_cut[maxn];
int n, m;

void tarjan( int u, int root )
{
    dfn[u] = low[u] = ++ timer;
    int childcnt = 0;
    for( int v : adj[u] )
    {
        if( !dfn[v] )
        {
            childcnt ++;
            tarjan( v, root );
            low[u] = min( low[u], low[v] );
            if( u != root && low[v] >= dfn[u] ) is_cut[u] = true;
        }
        else low[u] = min( low[u], dfn[v] );
    }
    if( u == root && childcnt >= 2 ) is_cut[u] = true;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i, i );
    }

    vector< int > cuts;
    for( int i = 1; i <= n; ++ i )
    {
        if( is_cut[i] ) cuts.push_back( i );
    }

    cout << cuts.size( ) << '\n';
    for( int cut : cuts ) cout << cut << ' ';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}