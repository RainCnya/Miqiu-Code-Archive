#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 3e3 + 5;

vector< int > adj[maxn];
int dist[maxn];
int a[maxn];
ll dp[maxn];
int n, m, T;

void bfs( int start )
{
    queue< int > q;
    q.push( start );
    dist[1] = 0;

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );

        for( int v : adj[u] )
        {
            if( dist[v] == -1 )
            {
                dist[v] = dist[u] + 1;
                q.push( v );
            }
        }
    }
}

void solve( )
{
    cin >> n >> m >> T;
    for( int i = 2; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset( dist, -1, sizeof( dist ) );

    bfs( 1 );

    for( int i = 2; i <= n; ++ i )
    {
        if( dist[i] == -1 ) continue;
        for( int j = 2 * dist[i]; j <= T; ++ j )
        {
            dp[j] = max( dp[j], dp[j - 2 * dist[i]] + a[i] );
        }
    }

    for( int k = 1; k <= T; ++ k )
    {
        cout << dp[k] << " ";
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
//  cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}