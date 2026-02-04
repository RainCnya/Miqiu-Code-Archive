#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 200 + 50;
const int maxp = 13;
const int inf = 1e9;

struct Edge { int to, time, need; };
struct Node { 
    int d, u, mask;
    bool operator < ( const Node &a ) const { return d > a.d; }
};

int dist[maxn][ 1 << maxp ];
int sword[maxn];
vector< Edge > adj[maxn];
int n, m, p, k;

void dijkstra( )
{
    memset( dist, 127, sizeof( dist ) );
    priority_queue< Node > pq;

    int start_mask = sword[1];
    dist[1][start_mask] = 0;
    pq.push({ 0, 1, start_mask });
    
    while( !pq.empty( ) )
    {
        auto [d, u, mask] = pq.top( );
        pq.pop( );

        if( d > dist[u][mask] ) continue;

        for( auto [v, t, need] : adj[u] )
        {
            if( ( mask & need ) != need ) continue;
            int next_mask = mask | sword[v];
            if( dist[v][next_mask] > d + t )
            {
                dist[v][next_mask] = d + t;
                pq.push({ dist[v][next_mask], v, next_mask });
            }
        }
    }
}

void solve( )
{
    cin >> n >> m >> p >> k;

    for( int i = 1; i <= k; ++ i )
    {
        int w, q, r, mask = 0;
        cin >> w >> q;
        while( q -- )
        {
            cin >> r;
            mask |= ( 1 << (r - 1) );
        }
        sword[w] |= mask;
    }

    for( int i = 1; i <= m; ++ i )
    {
        int v, w, t, s, u, mask = 0;
        cin >> v >> w >> t >> s;
        while( s -- )
        {
            cin >> u;
            mask |= ( 1 << (u - 1) );
        }
        adj[v].push_back({ w, t, mask });
        adj[w].push_back({ v, t, mask });
    }

    dijkstra( );

    int ans = inf;

    for( int mask = 0; mask < (1 << p); ++ mask )
        ans = min( ans, dist[n][mask] );

    if( ans == inf ) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}