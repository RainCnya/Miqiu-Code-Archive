#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 16000 + 5;

vector< int > adj[maxn];
int a[maxn];
int f[maxn];
// f[i] 表示以 i 为根的子树的最大点权
int n;

void dfs( int u, int p )
{
    f[u] = a[u];
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
        if( f[v] > 0 ) f[u] += f[v];
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    dfs( 1, 0 );

    int ans = -1e9;
    for( int i = 1; i <= n; ++ i ) ans = max( ans, f[i] );
    cout << ans << '\n';

    return 0;
}