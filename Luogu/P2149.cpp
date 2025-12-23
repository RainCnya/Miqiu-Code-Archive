#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using ll = long long;

const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;

vector<PII> adj[maxn];
int d1[maxn], d2[maxn], d3[maxn], d4[maxn];
int memo[maxn], n, m;
int X1, X2, Y1, Y2;

void dijkstra( int st, int dist[] )
{
    for( int i = 1; i <= n; ++ i ) dist[i] = inf;
    dist[st] = 0;

    priority_queue< PII, vector<PII>, greater<PII> > pq;
    pq.push({ 0, st });

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
        pq.pop( );
        if( d > dist[u] ) continue;
        for( auto [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

int dfs( int u, bool dir )
{
    if( memo[u] != -1 ) return memo[u];
    int len = 0;
    for( auto& [v, w] : adj[u] )
    {
        if( d1[u] + w + d2[v] != d1[Y1] ) continue;

        bool ok = 0;
        if( dir ) ok = ( d3[u] + w + d4[v] == d3[Y2] );
        else ok = ( d3[v] + w + d4[u] == d3[Y2] );

        if( ok ) len = max( len, w + dfs( v, dir ) );
    }
    return memo[u] = len;
}

int main( )
{
    cin >> n >> m;
    cin >> X1 >> Y1 >> X2 >> Y2;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra( X1, d1 );
    dijkstra( Y1, d2 );
    dijkstra( X2, d3 );
    dijkstra( Y2, d4 );

    int ans = 0;

    memset( memo, -1, sizeof( memo ) );
    for( int i = 1; i <= n; ++ i )
        ans = max( ans, dfs( i , 0 ) );

    memset( memo, -1, sizeof( memo ) );
    for( int i = 1; i <= n; ++ i )
        ans = max( ans, dfs( i , 1 ) );

    cout << ans << '\n';
    return 0;
}