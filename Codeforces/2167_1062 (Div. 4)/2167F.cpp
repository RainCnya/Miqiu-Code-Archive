#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

vector<int> adj[maxn];
int sz[maxn];
int n, k;

void dfs( int u, int fa )
{
    sz[u] = 1;
    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        dfs( v, u );
        sz[u] += sz[v];
    }
}

void solve( )
{
    cin >> n >> k;

    for( int i = 1; i <= n; i ++ ) adj[i].clear( );
    memset( sz, 0, sizeof( sz ) );

    for( int i = 1; i < n; i ++ ) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 1, 0 );

    ll ans = 0;
    for( int u = 1; u <= n; ++ u )
    {
        ans ++;

        for( int v : adj[u] )
        {
            int s;
            if( sz[v] < sz[u] ) s = sz[v];
            else s = n - sz[u];

            if( n - s >= k ) ans += s;
        }
    }
    
    cout << ans << '\n';
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
