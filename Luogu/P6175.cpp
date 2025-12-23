#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 105;
const int inf = 1e9;

ll dis[maxn][maxn];
ll adj[maxn][maxn];
int n, m;

int main( )
{
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            if( i == j ) dis[i][j] = adj[i][j] = 0;
            else dis[i][j] = adj[i][j] = inf;
        }
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        ll d;
        cin >> u >> v >> d;

        adj[u][v] = min( adj[u][v], d );
        adj[v][u] = min( adj[v][u], d );
        dis[u][v] = min( dis[u][v], d );
        dis[v][u] = min( dis[v][u], d );
    }

    ll ans = inf;
    for( int k = 1; k <= n; ++ k )
    {
        for( int i = 1; i < k; ++ i )
        {
            for( int j = i + 1; j < k; ++ j )
            {
                ll cur = dis[i][j] + adj[i][k] + adj[k][j];
                if( cur < ans ) ans = cur;
            }
        }
        for( int i = 1; i <= n; ++ i )
        {
            for( int j = 1; j <= n; ++ j )
            {
                if( dis[i][k] + dis[k][j] < dis[i][j] )
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }

    if( ans == inf ) cout << "No solution." << '\n';
    else cout << ans << '\n';

    return 0;
}