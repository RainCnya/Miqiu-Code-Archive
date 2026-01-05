#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PID = pair<int, double>;

const int maxn = 3000 + 5;
const int inf = 1e9;

vector<PID> adj[maxn];
double dis[maxn];
bool vis[maxn];
int n, m;

bool dfs( int u, double lim )
{
    vis[u] = 1;
    
    for( auto [v, w] : adj[u] )
    {
        w -= lim;
        if( dis[u] + w < dis[v] )
        {
            dis[v] = dis[u] + w;
            if( vis[v] ) return 1;
            if( dfs( v, lim ) ) return 1;
        }
    }
    vis[u] = 0;
    return 0;
}

bool check( double lim )
{
    for( int i = 1; i <= n; ++ i )
    {
        dis[i] = 0;
        vis[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( dfs( i, lim ) ) return 1;
    }
    return 0;
}

int main( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        double w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    double l = -1e7, r = 1e7;
    double ans = 0;

    for( int k = 1; k <= 100; ++ k )
    {
        double mid = ( l + r ) / 2.0;
        if( check( mid ) ) ans = mid, r = mid;
        else l = mid;
    }

    cout << fixed << setprecision( 8 )  << ans << '\n';
    return 0;
}