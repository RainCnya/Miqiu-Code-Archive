#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;
const int inf = 0x3f3f3f3f;

vector< int > adj[maxn];
int siz[maxn];
int f[maxn];
int n;

void dfs( int u , int fa )
{
    siz[u] = 1;
    f[u] = 0;
    
    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        dfs( v, u );
        siz[u] += siz[v];
        f[u] = max( f[u], siz[v] );
    }

    f[u] = max( f[u], n - siz[u] );
}

int main( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) f[i] = inf;

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }       

    dfs( 1, 0 );

    int root_sum = inf;
    int root_pos = 1;

    for( int i = 1; i <= n; ++ i )
    {
        if( f[i] < root_sum )
        {
            root_sum = f[i];
            root_pos = i;
        }
    }

    cout << root_pos << " ";

    memset( siz, 0, sizeof( siz ) );
    dfs( root_pos, 0 );

    ll ans = 0;

    for( int i = 1; i <= n; ++ i )
    {
        ans += siz[i];
    }

    cout << ans - n << '\n';
    return 0;
}