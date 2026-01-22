#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int N = 1000 + 5;

vector<pair<int, int>> edges;
vector<int> adj1[N];
vector<tuple<int, int, int>> gragh;
int n, m;
int dist[N], cnt[N];
bool vis[N], tag[N];

void dfs( int u )
{
    for( auto& edge : adj1[u] )
    {
        int v = edge;
        if( !vis[v] )
        {
            vis[v] = 1;
            dfs( v );
        }
        if( tag[v] )
            tag[u] = 1;
    }
}

int main( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back( v );
        edges.push_back( { u, v } );
    }
    memset( vis, 0, sizeof( vis ) );
    vis[1] = 1;
    tag[n] = 1;
    dfs( 1 );
    for( auto& edge : edges )
    {
        int u = edge.first;
        int v = edge.second;
        if( tag[u] && tag[v] )
        {
            gragh.emplace_back( u, v, 2 );
            gragh.emplace_back( v, u, -1 );
        }
    }

    for( int i = 1; i <= n; ++ i )
        dist[i] = inf;
    dist[1] = 0;

    for( int i = 1; i < n; ++ i )
    {
        for( auto& edge : gragh )
        {
            int u, v, w;
            tie( u, v, w ) = edge;
            if( dist[u] != inf && dist[v] > dist[u] + w )
                dist[v] = dist[u] + w;
        }
    }
    bool check = false;
    for( auto& edge : gragh )
    {
        int u, v, w;
        tie( u, v, w ) = edge;
        if( dist[u] != inf && dist[v] > dist[u] + w )
        {
            check = true;
            break;
        }
    }
    if( check )
    {
        cout << "No" << endl;
        return 0;
    }
    else
    {
        cout << "Yes" << endl;
        for( auto& edge : edges )
        {
            int u = edge.first;
            int v = edge.second;
            if( tag[u] && tag[v] )
                cout << dist[v] - dist[u] << endl;
            else
                cout << 1 << endl;
        }
    }
    return 0;
}