#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 50;
const int inf = 0x3f3f3f3f;

vector< int > adj[maxn];
ll siz[maxn];
ll f[maxn];
int w[maxn];
ll sum, ans = inf;
int n;

void dfs1( int u, int fa, int dep )
{
    siz[u] = w[u];
    f[1] += (ll)w[u] * dep;

    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        dfs1( v, u, dep + 1 );
        siz[u] += siz[v];
    }
}

void dfs2( int u, int fa )
{

    if( f[u] < ans ) ans = f[u];

    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        f[v] = f[u] - siz[v] + ( sum - siz[v] );
        dfs2( v, u );
    }
}

void add( int u, int v )
{
    adj[u].push_back( v );
    adj[v].push_back( u );
}

int main( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) f[i] = inf;

    for( int i = 1; i <= n; ++ i )
    {
        int _w, u, v;
        cin >> _w >> u >> v;
        if( u != 0 ) add( i, u );
        if( v != 0 ) add( i, v );
        w[i] = _w;
        sum += _w;
    }

    f[1] = 0;

    dfs1( 1, 0, 0 );
    dfs2( 1, 0 );

    cout << ans << '\n';
    return 0;
}