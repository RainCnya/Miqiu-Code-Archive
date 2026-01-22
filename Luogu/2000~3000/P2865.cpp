#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair< ll, ll >;

const int maxn = 5e3 + 5;
const int inf = 1e9;

struct Edge {
    int to;
    ll cost;
    bool operator < ( const Edge& other ) const {
        return cost > other.cost;
    }
};

vector< Edge > adj[maxn];
ll dist[maxn][2];
int n, m;

void dijkstra( int st )
{
    for( int i = 1; i <= n; ++ i )
    {
        dist[i][0] = dist[i][1] = inf;
    }

    dist[st][0] = 0;

    priority_queue< Edge > pq;
    pq.push( { st, 0 } );

    while( !pq.empty( ) )
    {
        auto [u, d] = pq.top( );
        pq.pop( );

        if( d > dist[u][1] ) continue;

        for( auto& [to, cost] : adj[u] )
        {
            ll nd = d + cost;
            if( nd < dist[to][0] )
            {
                if( dist[to][0] != inf )
                {
                    dist[to][1] = dist[to][0];
                    pq.push({ to, dist[to][1] });
                }
                dist[to][0] = nd;
                pq.push({ to, dist[to][0] });
            }
            else if( dist[to][0] < nd && nd < dist[to][1] )
            {
                dist[to][1] = nd;
                pq.push({ to, dist[to][1] });
            }
        }
    }
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;   ll w;
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
    
    solve( );
    return 0;
}
