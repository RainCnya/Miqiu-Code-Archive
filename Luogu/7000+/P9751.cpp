#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
const int maxk = 100 + 5;
const ll inf = 1e18;

struct Edge { int v, a; };

vector< Edge > adj[maxn];

ll dp[maxn][maxk];
bool vis[maxn][maxk];
int n, m, k;

struct State { 
    int u, t;
    bool operator < ( const State& oth ) const { return t > oth.t; }
};

void bfs( )
{
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 0; j <= k; ++ j )
        {
            dp[i][j] = inf;
        }
    }

    priority_queue< State > q;
    
    q.push({ 1, 0 });
    dp[1][0] = 0;
    
    while( !q.empty( ) )
    {
        auto [u, t] = q.top( );
        q.pop( );

        if( vis[u][t % k] ) continue;
        vis[u][t % k] = true;

        for( auto& [v, a] : adj[u] )
        {
            int wait = 0;
            if( t < a ) wait = ( a - t + k - 1 ) / k * k;
            int nt = t + wait + 1;
            if( nt < dp[v][nt % k] )
            {
                dp[v][nt % k] = nt;
                q.push({ v, nt });
            }
        }
    }
}


void solve( )
{
    cin >> n >> m >> k;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, a;
        cin >> u >> v >> a;
        adj[u].push_back({ v, a });
    }

    bfs( );

    if( dp[n][0] == inf ) cout << "-1" << "\n";
    else cout << dp[n][0] << "\n";
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}