#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;
const int inf = 1e9 + 7;

vector< int > adj[maxn];
int dist[maxn];
int n, k, v;

void dfs( int u, int p )
{
    bool leaf = 1;
    int min1 = inf, min2 = inf;

    for( int v : adj[u] )
    {
        if( v == p ) continue;
        leaf = 0;
        dfs( v, u );
        if( dist[v] < min1 ) min2 = min1, min1 = dist[v];
        else if( dist[v] < min2 ) min2 = dist[v];
    }

    if( leaf ) dist[u] = 0;
    else {
        if( min2 != inf && min1 + min2 <= k - 1 ) dist[u] = 0;
        else dist[u] = min1 + 1;
    }
}

void solve( )
{
    cin >> n >> k >> v;

    for( int i = 1; i <= n; ++ i ) 
    {
        adj[i].clear( );
        dist[i] = inf;
    }
    
    for( int i = 1; i <= n - 1; ++ i )
    {
        int a, b; cin >> a >> b;
        adj[a].push_back( b );
        adj[b].push_back( a );
    }

    dfs( v, 0 );

    if( dist[v] == 0 ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}