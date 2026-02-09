#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const int maxlg = 20;

struct Edge { int v, w; };
vector< Edge > adj[maxn];

int dep[maxn];
int up[maxn][maxlg];
ll dist[maxn];
int a[maxn];
int n, k;

void dfs( int u, int fa, int d, ll dis )
{
    dep[u] = d;
    dist[u] = dis;
    up[u][0] = fa;

    for( int i = 1; i < maxlg; ++ i )
        up[u][i] = up[ up[u][i - 1] ][i - 1];
    
    for( auto [v, w] : adj[u] )
    {
        if( v == fa ) continue;
        dfs( v, u, d + 1, dis + w );
    }
}

int get_lca( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = 0; i < maxlg; ++ i )
        if( ( diff >> i ) & 1 ) u = up[u][i];
    
    if( u == v ) return u;
    for( int i = maxlg - 1; i >= 0; -- i )
        if( up[u][i] != up[v][i] )
            u = up[u][i], v = up[v][i];
    
    return up[u][0];
}

ll get_dist( int u, int v )
{
    int lca = get_lca( u, v );
    return dist[u] + dist[v] - 2 * dist[lca];
}

void solve( )
{
    cin >> n >> k;

    for( int i = 1; i < n; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    for( int i = 1; i <= k; ++ i ) cin >> a[i];

    dfs( 1, 1, 0, 0 );

    ll sum = 0;

    for( int i = 1; i < k; ++ i ) sum += get_dist( a[i], a[i + 1] );

    vector< ll > anss;

    for( int i = 1; i <= k; ++ i )
    {
        ll res = sum;
        if( i == 1 )
        {
            res -= get_dist( a[i], a[i + 1] );
            anss.push_back( res );
        }
        else if( i == k )
        {
            res -= get_dist( a[i - 1], a[i] );
            anss.push_back( res );
        }
        else
        {
            res -= get_dist( a[i], a[i + 1] );
            res -= get_dist( a[i - 1], a[i] );
            res += get_dist( a[i - 1], a[i + 1] );
            anss.push_back( res );
        }
    }

    for( int i = 0; i < k; ++ i )
    {
        cout << anss[i];
        if( i != k - 1 ) cout << ' ';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}