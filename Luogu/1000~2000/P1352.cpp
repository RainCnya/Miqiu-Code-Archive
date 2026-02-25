#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 6e3 + 5;

vector< int > adj[maxn];

ll f[maxn][2];
// f[u][0/1] 0不选 / 1选 u 的最大价值
int a[maxn];
int n;

void dfs( int u, int p )
{
    f[u][1] = a[u];
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u );
        f[u][0] += max( f[v][0], f[v][1] );
        f[u][1] += f[v][0];
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
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 1, 0 );

    cout << max( f[1][0], f[1][1] ) << '\n';
    return 0;
}