#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;
const ll inf = 1e18;

struct Edge { int u, v; };

vector< int > adj[maxn];
vector< Edge > edges;

ll sz[maxn], val[maxn];
int dep[maxn], fa[maxn], w[maxn];
int son1[maxn], son2[maxn];
int n;

void dfs( int u, int p, int d )
{
    sz[u] = w[u];
    val[u] = 0;
    dep[u] = d;
    fa[u] = p;
    son1[u] = son2[u] = 0;
    
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u, d + 1 );

        sz[u] += sz[v];
        val[u] += val[v] + sz[v];

        if( sz[v] > sz[son1[u]] ) son2[u] = son1[u], son1[u] = v;
        else if( sz[v] > sz[son2[u]] ) son2[u] = v;
    }
}

void calc( int u, ll cur_val, int sz_sum, int del, ll &res )
{
    res = min( res, cur_val );

    int son = son1[u];
    if( son1[u] == del || ( son2[u] && sz[son2[u]] > sz[son1[u]] ) ) son = son2[u];

    if( son == del || son == 0 ) return;

    if( sz[son] * 2 > sz_sum )
    {
        calc( son, cur_val + sz_sum - 2 * sz[son] , sz_sum, del, res );
    }

}

void solve( )
{
    cin >> n;

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
        edges.push_back({ u, v });
    }

    for( int i = 1; i <= n; ++ i ) cin >> w[i];

    dfs( 1, 0, 0 );

    ll ans = inf;

    for( auto [u, v] : edges )
    {
        if( fa[v] != u ) swap( u, v );

        for( int cur = u; cur; cur = fa[cur] ) sz[cur] -= sz[v];

        ll res_up = inf, res_down = inf;

        ll cost = val[1] - ( val[v] + sz[v] * dep[v] );

        calc( 1, cost, sz[1], v, res_up );
        calc( v, val[v], sz[v], 0, res_down );

        ans = min( ans, res_up + res_down );

        for( int cur = u; cur; cur = fa[cur] ) sz[cur] += sz[v];
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}