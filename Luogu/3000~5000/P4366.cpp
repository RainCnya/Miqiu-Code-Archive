#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const ll inf = 1e18;

struct Edge { int v; ll w; };
vector< Edge > adj[maxn];
int A, B;
int n, m, c;

ll dist[maxn];
struct Node { 
    int u; ll d; 
    bool operator < ( const Node &oth ) const { return d > oth.d; }
};


void build( )
{
    for( int i = 0; i <= n; ++ i )
    {
        for( int j = 0; (1 << j) <= n; ++ j )
        {
            if( (i ^ (1 << j)) > n ) continue;
            adj[i].push_back({ i ^ (1 << j), (1 << j) * c });
        }
    }
}

void dijkstra( int s )
{
    for( int i = 0; i <= n; ++ i ) dist[i] = inf;
    dist[s] = 0;

    priority_queue< Node > pq;
    pq.push({s, 0});

    while( !pq.empty( ) )
    {
        auto [u, d] = pq.top( );
        pq.pop( );

        if( d > dist[u] ) continue;
        for( auto [v, w] : adj[u] )
        {
            if( dist[v] > dist[u] + w )
            {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }
}

void solve( )
{
    cin >> n >> m >> c;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    cin >> A >> B;
    build( );
    dijkstra( A );
    cout << dist[B] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}