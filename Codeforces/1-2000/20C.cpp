#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e18;
const int N = 1e5 + 5;

int n, m;
vector<pair<int, long long>> adj[N];
int pre[N];
long long dis[N];

long long dijkstra( int start, int end )
{
    for( int i = 1; i <= n; ++ i )
        dis[i] = inf;
    memset( pre, 0, sizeof( pre ) );
    priority_queue<pair<long long, int>> pq;
    pq.push( { 0, start } );
    dis[start] = 0;
    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( ); pq.pop( );
        d = -d;
        if( d > dis[u] ) continue;
        for( auto [v, w] : adj[u] )
        {
            if( dis[u] + w < dis[v] )
            {
                pre[v] = u;
                dis[v] = dis[u] + w;
                pq.push( { -dis[v], v } );
            }
        }
    }
    return dis[end];
}

int main( )
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back( {v, w} );
        adj[v].push_back( {u, w} );
    }
    long long ans = -1;
    ans = dijkstra( 1, n );
    if( dis[n] == inf )
    {
        cout << -1;
        return 0;
    }
    vector<int> paths;
    int cur = n;
    while( cur != 0 )
    {
        paths.push_back( cur );
        cur = pre[cur];
    }
    reverse( paths.begin( ), paths.end( ) );
    for( int x : paths )
    {
        cout << x << " ";
    }
    return 0;
}