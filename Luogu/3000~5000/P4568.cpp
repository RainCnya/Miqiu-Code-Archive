#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;
const int maxk = 10 + 5;
const ll inf = 1e18;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
ll dist[maxn][maxk];
bool vis[maxn][maxk];
int n, m, k, s, t;

struct State {
    int u, k;
    ll d;
    bool operator < ( const State& oth ) const { return d > oth.d; }
};

void dijkstra( int s )
{
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 0; j <= k; ++ j )
        {
            dist[i][j] = inf;
            vis[i][j] = false;
        }
    }

    priority_queue< State > pq;
    pq.push({ s, 0, 0 });
    dist[s][0] = 0;

    while( !pq.empty( ) ) 
    {
        auto [u, nk, d] = pq.top( );
        pq.pop( );

        if( vis[u][nk] ) continue;
        vis[u][nk] = true;

        for( auto& [v, w] : adj[u] ) 
        {
            if( dist[v][nk] > dist[u][nk] + w ) 
            {
                dist[v][nk] = dist[u][nk] + w;
                pq.push({ v, nk, dist[v][nk] });
            }
            if( nk < k && dist[v][nk+1] > dist[u][nk] ) 
            {
                dist[v][nk+1] = dist[u][nk];
                pq.push({ v, nk+1, dist[v][nk+1] });
            }
        }
    }
}

void solve( )
{
    cin >> n >> m >> k >> s >> t;
    s ++, t ++;
    for( int i = 1; i <= m; ++ i ) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        u ++, v ++;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra( s );

    ll ans = inf;
    for( int i = 0; i <= k; ++ i ) ans = min( ans, dist[t][i] );
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}