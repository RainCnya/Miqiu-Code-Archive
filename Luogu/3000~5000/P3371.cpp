#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
const int maxm = 5e5 + 5;
const ll inf = 1e18;

struct Edge { int u, v, w; } edges[maxm];
ll dist[maxn];
int n, m, s;

bool bellman_ford( int s ) 
{
    fill( dist, dist + n + 1, inf );
    dist[s] = 0;

    for( int i = 1; i <= n - 1; ++ i )
    {
        for( auto &[u, v, w] : edges ) 
        {
            dist[v] = min( dist[v], dist[u] + w );
        }
    }

    for( auto &[u, v, w] : edges ) 
    {
        if( dist[u] != inf && dist[v] > dist[u] + w ) 
            return true;
    }
    return false;
}

int main( ) 
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    
    cin >> n >> m >> s;

    for( int i = 1; i <= m; ++ i ) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = { u, v, w };
    }

    bellman_ford( s );
    
    for( int i = 1; i <= n; ++ i ) 
    {
        if( dist[i] == inf ) cout << "2147483647" << ' ';
        else cout << dist[i] << ' ';
    }
    
    return 0;
}