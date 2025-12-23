#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

vector< int > adj[maxn];

int distA[maxn], distB[maxn];
int pre[maxn];
bool is_path[maxn];
vector< int > path;
int nodeA, nodeB;
int n;

struct Op { int u, v, rem; };
vector< Op > ops;
ll ans;

int bfs( int start, int dist[], bool flag )
{
    for( int i = 1; i <= n; ++ i ) dist[i] = -1;
    if( flag ) {
        for( int i = 1; i <= n; ++ i ) pre[i] = 0;
    }

    queue< int > q;
    q.push( start );
    dist[start] = 0;

    int root = start;
    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );

        if( dist[u] > dist[root] ) root = u;

        for( int v : adj[u] )
        {
            if( dist[v] == -1 )
            {
                dist[v] = dist[u] + 1;
                if( flag ) pre[v] = u;
                q.push( v );
            }
        }
    }
    return root;
}

void dfs( int u, int fa )
{
    for( int v : adj[u] )
    {
        if( v == fa || is_path[v] ) continue;
        dfs( v, u );
    }

    if( distA[u] > distB[u] )
    {
        ans += distA[u];
        ops.push_back({ nodeA, u, u });
    }
    else
    {
        ans += distB[u];
        ops.push_back({ nodeB, u, u });
    }
}

int main( )
{
    cin >> n;
    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    nodeA = bfs( 1, distA, 0 );
    nodeB = bfs( nodeA, distA, 1 );
    bfs( nodeB, distB, 0 );

    int cur = nodeB;
    while( cur != 0 )
    {
        is_path[cur] = 1;
        path.push_back( cur );
        cur = pre[cur];
    }

    for( int u : path )
    {
        for( int v : adj[u] )
        {
            if( !is_path[v] )
            {
                dfs( v, u );
            }
        }
    }

    for( int i = 0; i < path.size( ) - 1; ++ i )
    {
        int u = path[i];
        ans += distA[u];
        ops.push_back( { nodeA, u, u } );
    }

    cout << ans << '\n';

    for( auto [u, v, rmv] : ops )
    {
        cout << u << " " << v << " " << rmv << '\n';
    }
    
    return 0;
}