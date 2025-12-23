#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

struct Edge {
    int v, w;
};

vector< Edge > adj[maxn];
int S1, S2, n;
int dis[maxn];

void dfs( int u, int fa )
{
    for( auto [v, w] : adj[u] )
    {
        if( v == fa ) continue;
        dis[v] = dis[u] + w;
        dfs( v, u );
    }
}

void Work( )
{
    int maxVal = -1;
    dfs( 1, 0 );
    for( int i = 1; i <= n; ++ i )
    {
        if( dis[i] > maxVal )
            maxVal = dis[i], S1 = i;
    }
    memset( dis, 0, sizeof( dis ) );
    maxVal = -1;
    dfs( S1, 0 );
    for( int i = 1; i <= n; ++ i )
    {
        if( dis[i] > maxVal )
            maxVal = dis[i], S2 = i;
    }
}

int main( )
{
    cin >> n;
    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({ v, 1 });
        adj[v].push_back({ u, 1 });
    }

    Work( );

    cout << dis[S2] << '\n';
    return 0;
}