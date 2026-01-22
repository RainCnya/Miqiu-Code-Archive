#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 50;
const int inf = 0x3f3f3f3f;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
int distA[maxn], distB[maxn];
int pre[maxn];

bool is_path[maxn];
vector< int > path;

int branch[maxn];

int nodeA, nodeB;
int ans = inf;
int n, s;

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

        for( auto [v, w] : adj[u] )
        {
            if( dist[v] == -1 )
            {
                dist[v] = dist[u] + w;
                if( flag ) pre[v] = u;
                q.push( v );
            }
        }
    }
    return root;
}

int dfs_branch( int u, int fa )
{
    int max_d = 0;
    for( auto [v, w] : adj[u] )
    {
        if( v == fa || is_path[v] ) continue;
        max_d = max( max_d, dfs_branch( v, u ) + w ); 
    }
    return max_d;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> s;
    for( int i = 1; i < n; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    nodeA = bfs( 1, distA, 0 );
    nodeB = bfs( nodeA, distA, 1 );
    bfs( nodeB, distB, 0 );

    int cur = nodeB;
    while( cur != 0 )
    {
        is_path[cur] = 1;
        path.push_back( cur );
        cur= pre[cur];
    }

    for( int u : path )
    {
        branch[u] = dfs_branch( u, 0 );
    }

    for( int i = 0; i < path.size( ); ++ i )
    {
        for( int j = i; j < path.size( ); ++ j )
        {
            int u = path[i], v = path[j];
            int len = abs( distA[u] - distA[v] );
            if( len > s ) continue;

            int max_val = 0;
            for( int k = i; k <= j; ++ k )
            {
                max_val = max( max_val, branch[ path[k] ] );
            }
            int cur_ecc = max( max_val, max( distB[u], distA[v] ) );
            ans = min( ans, cur_ecc );
        }
    }

    cout << ans << '\n';
    return 0;
}