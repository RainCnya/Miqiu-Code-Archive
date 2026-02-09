#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int maxm = 3e5 + 5;
const int maxlg = 20;
const ll inf = 1e18;

struct Edge {
    int u, v; ll w;
    bool operator < ( const Edge &oth ) const { return w < oth.w; }
} edges[maxm];

struct Node { int v; ll w; };
vector< Node > adj[maxn];

int up[maxn][maxlg];
ll max1[maxn][maxlg];
ll max2[maxn][maxlg];

int fa[maxn], dep[maxn];
bool is_mst[maxm];
ll mst_weight;
int n, m;

int find( int x ) 
{ 
    if( x == fa[x] ) return fa[x];
    else return fa[x] = find( fa[x] );
}

void dfs( int u, int p, ll w )
{
    dep[u] = dep[p] + 1;
    up[u][0] = p;
    max1[u][0] = w;
    max2[u][0] = -1;
    
    for( int i = 1; i < maxlg; ++ i )
    {
        up[u][i] = up[up[u][i - 1]][i - 1];
        int v1 = max1[u][i - 1], v2 = max1[up[u][i - 1]][i - 1];
        int v3 = max2[u][i - 1], v4 = max2[up[u][i - 1]][i - 1];

        max1[u][i] = max( v1, v2 );
        if( v1 == v2 ) max2[u][i] = max( v3, v4 );
        else max2[u][i] = max( max( v3, v4 ), min( v1, v2 ) );
    }
    
    for( auto& [v, w] : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u, w );
    }
}

bool kruskal( )
{
    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    sort( edges + 1, edges + m + 1 );

    mst_weight = 0;
    int cnt = 0;

    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w] = edges[i];
        int ru = find( u ), rv = find( v );
        if( ru != rv )
        {
            fa[ru] = rv;
            mst_weight += w;
            is_mst[i] = true;
            cnt ++;
            adj[u].push_back( { v, w } );
            adj[v].push_back( { u, w } );
            if( cnt == n - 1 ) break;
        }
    }
    return cnt == n - 1;
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

void update( ll &m1, ll &m2, ll v1, ll v2 ) 
{
    if( m1 < v1 ) {
        m2 = max( m1, v2 );
        m1 = v1;
    } else if( v1 < m1) {
        m2 = max( m2, v1 );
    } else { 
        m2 = max( m2, v2 );
    }
}

pair< ll, ll > query( int u, int anc )
{
    ll res1 = -1, res2 = -1;
    int diff = dep[u] - dep[anc];
    for( int i = 0; i < maxlg; ++ i )
    {
        if( ( diff >> i ) & 1 ) 
        {
            update( res1, res2, max1[u][i], max2[u][i] );
            u = up[u][i];
        }
    }   
    return { res1, res2 };
}

void solve( )
{
    cin >> n >> m;

    memset( max1, -1, sizeof( max1 ) );
    memset( max2, -1, sizeof( max2 ) );

    for( int i = 1; i <= m; ++ i ) cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    kruskal( );
    dfs( 1, 0, -1 );

    ll del = inf;
    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w] = edges[i];
        if( is_mst[i] || u == v ) continue;

        int lca = get_lca( u, v );

        auto m1 = query( u, lca );
        auto m2 = query( v, lca );

        ll res_m1 = -1, res_m2 = -1;

        update( res_m1, res_m2, m1.first, m1.second );
        update( res_m1, res_m2, m2.first, m2.second );

        if( w > res_m1 ) del = min( del, w - res_m1 );
        else if( res_m2 != -1 ) del = min( del, w - res_m2 );
    }
    
    cout << mst_weight + del << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}