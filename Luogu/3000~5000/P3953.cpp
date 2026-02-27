#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const ll inf = 1e18;

struct Edge { int v, w; };
vector< Edge > adj[maxn], radj[maxn];
bool vis[maxn][55];
ll dp[maxn][55];
// dp[u][k] 表示 1 -> u 路径上，距离为 disy[u] + k 的方案数
ll dist[maxn];
int n, m;
ll K, P;
bool cycle;

struct State {
    int u; ll d;
    bool operator < ( const State &oth ) const { return d > oth.d; }
};

void dijkstra( )
{
    for( int i = 1; i <= n; ++ i ) dist[i] = inf;
    dist[1] = 0;

    priority_queue< State > pq;
    pq.push({ 1, 0 });

    while( !pq.empty( ) )
    {
        auto [u, d] = pq.top( ); pq.pop( );
        if( d > dist[u] ) continue;

        for( auto [v, w] : adj[u] )
        {
            if( dist[v] > dist[u] + w )
            {
                dist[v] = dist[u] + w;
                pq.push({ v, dist[v] });
            }
        }
    }
}

ll dfs( ll u, ll k )
{
    if( k < 0 || k > K ) return 0;
    if( vis[u][k] ) 
    {
        cycle = true;
        return 0;
    }
    if( dp[u][k] != -1 ) return dp[u][k];

    vis[u][k] = true;
    ll res = 0;
    if( u == 1 && k == 0 ) res = 1;
    
    for( auto [v, w] : radj[u] )
    {
        ll nk = k - ( dist[v] + w - dist[u] );
        res = ( res + dfs( v, nk ) ) % P;
        if( cycle ) return 0;
    }

    vis[u][k] = false;
    return dp[u][k] = res;
}

void solve( )
{
    cin >> n >> m >> K >> P;

    for( int i = 1; i <= n; ++ i )
    {
        adj[i].clear( );
        radj[i].clear( );
    }
    
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        radj[v].push_back({ u, w });
    }

    dijkstra( );
    memset( vis, 0, sizeof( vis ) );
    memset( dp, -1, sizeof( dp ) );
    cycle = false;

    ll ans = 0;
    for( int i = 0; i <= K; ++ i )
    {
        ans = ( ans + dfs( n, i ) ) % P;
        if( cycle )
        {
            cout << -1 << '\n';
            return;
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
    while( _t -- ) solve( );
    return 0;
}