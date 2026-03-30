#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
const ll inf = 1e18;

vector< int > adj[maxn];
ll a[maxn], f[maxn];
ll sz[maxn], sum[maxn];
int n;

void dfs( int u, int p )
{
    sz[u] = 1;
    sum[u] = a[u];
    ll mn = inf;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
        sum[u] += sum[v];
        sz[u] += sz[v];
        mn = min( mn, f[v] );
    }
    ll avg = sum[u] / sz[u];
    if( mn == inf ) f[u] = avg;
    else f[u] = min( mn, avg );
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) adj[i].clear( );
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i < n; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }
    dfs( 1, 0 );
    for( int i = 1; i <= n; ++ i ) cout << f[i] << " ";
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}