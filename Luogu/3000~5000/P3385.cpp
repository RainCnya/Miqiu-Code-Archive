#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
const ll inf = 1e18;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
ll dist[maxn];
bool vis[maxn];
int n, m;

bool spfa( int u ) 
{
    vis[u] = true;
    for( auto& [v, w] : adj[u] ) 
    {
        if( dist[u] + w < dist[v] ) 
        {
            dist[v] = dist[u] + w;
            if( vis[v] ) return true;
            if( spfa( v ) ) return true;
        }
    }
    vis[u] = false;
    return false;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) 
    {
        adj[i].clear( );
        dist[i] = inf;
        vis[i] = false;
    }

    for( int i = 1; i <= m; ++ i ) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        if( w >= 0 ) adj[v].push_back({ u, w });
    }

    dist[1] = 0;
    if( spfa( 1 ) ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main( ) 
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}