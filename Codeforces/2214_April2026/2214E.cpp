#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const ll inf = 1e18;

struct Edge { int v; ll w; };
vector< Edge > adj[maxn];
ll dist[maxn];
int n, m;

void dijkstra( int start ) 
{
    fill( dist, dist + n + 1, inf );
    dist[start] = 0;
    
    for( int u = 1; u <= n; ++ u )
    {
        if( dist[u] == inf ) continue;

        for( auto [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] ) 
            {
                dist[v] = dist[u] + w;
            }
        }
    }
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) adj[i].clear( );

    for( int i = 1; i <= m; ++ i ) 
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra( 1 );
    for( int i = 2; i <= n; ++ i ) {
        if( dist[i] == inf ) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
    return ;
}

int main( ) 
{
    cin.tie(0)->sync_with_stdio(0);
    solve( );
    return 0;
}