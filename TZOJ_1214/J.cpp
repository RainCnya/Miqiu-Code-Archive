#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair< ll, ll >;

const int maxn = 5000 + 5;
const int inf = 1e9;

vector< PII > adj[maxn];
ll dist[maxn][2];
int n, m;

void dijkstra( int st )
{
    for( int i = 1; i <= n; ++ i )
    {
        dist[i][0] = dist[i][1] = inf;
    }

    dist[st][0] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push( { 0, st } );

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
        pq.pop( );

        if( d > dist[u][1] ) continue;

        for( auto& [v, w] : adj[u] )
        {
            int nd = d + w;
            if( nd < dist[v][0] )
            {
                if( dist[v][0] != inf )
                {
                    dist[v][1] = dist[v][0];
                    pq.push({ dist[v][1], v });
                }
                dist[v][0] = nd;
                pq.push({ dist[v][0], v });
            }
            else if( dist[v][0] < nd && nd < dist[v][1] )
            {
                dist[v][1] = nd;
                pq.push({ dist[v][1], v });
            }
        }
    }
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra( 1 );

    cout << dist[n][1] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
   //cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
