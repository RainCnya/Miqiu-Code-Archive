#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, t; cin >> n >> t;
    vector<int> adj[n + 1];
    for( int i = 1; i < n; ++ i )
    {
        int a; cin >> a;
        adj[ i ].push_back( i + a );
    }
    vector<int> vis( n + 1, 0 );
    queue<int> q;
    bool ok = 0;
    q.push( 1 );
    vis[1] = 1;
    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );
        if( u == t )
        {
            ok = 1;
            break;
        }
        for( int v : adj[u] )
        {
            if( !vis[v] )
            {
                vis[v] = 1;
                q.push( v );
            }
        }        
    }
    if( ok ) cout << "YES";
    else cout << "NO";
    return 0;
}
