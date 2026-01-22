#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
 
vector<int> adj[maxn]; // graph
int cnt[maxn]; // level
int dep[maxn]; // depth
int son[maxn]; // son_cnt
int n;

int bfs( int root )
{
    int lim = 0; // max_depth

    queue< int > q;
    q.push( root );
    dep[root] = 0;

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );
        cnt[dep[u]] ++;
        lim = max( lim, dep[u] );

        for( int v : adj[u] )
        {
            if( dep[v] != -1 ) continue;
            dep[v] = dep[u] + 1;
            son[u] ++;
            q.push( v );
        }
    }
    return lim;
}

void solve( )
{
    cin >> n;

    for( int i = 0; i <= n; ++ i )
    {
        adj[i].clear( );
        dep[i] = -1;
        son[i] = cnt[i] = 0;
    }

    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    int lim = bfs( 1 );

    int ans = 0;
    
    for( int i = 0; i <= lim; ++ i )
    {
        ans = max( ans, cnt[i] );
    }

    for( int i = 1; i <= n; ++ i )
    {
        ans = max( ans, son[i] + 1 ); // son + father
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}