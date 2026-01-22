#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 5;
const int M = 2e5 + 5;

int n, m;
vector<int> adj[N];
vector<int> cur;
bool vis[N];

void dfs( int u )
{
    vis[u] = 1;
    cur.push_back( u );
    for( int v : adj[u] )
    {
        if( !vis[v] )
            dfs( v );
    }
}

int main()
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[ u ].push_back( v );
        adj[ v ].push_back( u );
    }
    int ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( !vis[i] )
        {
            cur.clear( );
            dfs( i );
            bool check = 1;
            if( cur.empty( ) ) 
            {
                check = 0;
                break;
            }
            for( int u : cur )
            {
                if( adj[u].size( ) != 2 )
                {
                    check = 0;
                    break;
                }
            }
            if( check ) ans ++;
        }
    }
    cout << ans;
    return 0;
}
