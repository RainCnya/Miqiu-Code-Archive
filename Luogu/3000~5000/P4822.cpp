#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 50 + 5;
const int maxk = 50 + 5;
const ll inf = 1e18;


struct Edge { int v, w; };

vector< Edge > adj[maxn];
ll dist[maxn][maxk];
bool vis[maxn][maxk];
int n, m, k;

struct State { 
    int u, k;
    ll d;
    bool operator < ( const State& oth ) const { return d > oth.d; }
};

void dijkstra( )
{
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 0; j <= k; ++ j )
        {
            dist[i][j] = inf;
        }
    }

    priority_queue< State > q;
    q.push({ 1, 0, 0 });
    dist[1][0] = 0;

    while( !q.empty( ) )
    {
        auto [u, nk, d] = q.top( );
        q.pop( );

        if( vis[u][nk] ) continue;
        vis[u][nk] = true;

        for( auto& [v, w] : adj[u] )
        {
            if( dist[u][nk] + w < dist[v][nk] )
            {
                dist[v][nk] = dist[u][nk] + w;
                q.push({ v, nk, dist[v][nk] });
            }

            if( nk < k && dist[u][nk] + w / 2 < dist[v][nk+1] )
            {
                dist[v][nk+1] = dist[u][nk] + w / 2;
                q.push({ v, nk+1, dist[v][nk+1] });
            }
        }
    }
}


void solve( )
{
    cin >> n >> m >> k;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra( );
    ll ans = inf;
    for( int i = 0; i <= k; ++ i )
    {
        ans = min( ans, dist[n][i] );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}