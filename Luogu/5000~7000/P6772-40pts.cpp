#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 50 + 5;
const ll inf = 1e18;

map< pair< int , int >, int > fest;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
ll dp[100000][maxn];
// dp[t][u] 第 t 天，走到 u 点的最大值
ll c[maxn];
int n, m, T, k;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> T >> k;
    for( int i = 1; i <= n; ++ i ) cin >> c[i];

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    for( int i = 1; i <= k; ++ i )
    {
        int t, x, y;
        cin >> t >> x >> y;
        fest[{ t, x }] = y;
    }

    for( int i = 0; i <= T; ++ i )
    {
        for( int u = 1; u <= n; ++ u )
        {
            dp[i][u] = -inf;
        }
    }

    dp[0][1] = c[1];
    for( int i = 0; i <= T; ++ i )
    {
        for( int u = 1; u <= n; ++ u) 
        {
            if( dp[i][u] < 0 ) continue;
            for( auto [v, w] : adj[u] )
            {
                int nxt = i + w;
                if( nxt <= T )
                {
                    ll gain = c[v] + fest[{ nxt, v }];
                    dp[nxt][v] = max( dp[nxt][v], dp[i][u] + gain );
                }
            }
        }
    }

    if( dp[T][1] < 0 ) cout << -1 << '\n';
    else cout << dp[T][1] << '\n';
    return 0;
}