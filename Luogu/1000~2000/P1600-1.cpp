#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;
const int maxlg = 20;

struct Path { int s, t, lca, dist; } p[maxn];
struct Seg { int opt, val; };
vector< Seg > add[maxn], del[maxn];
vector< int > adj[maxn];
int dep[maxn], up[maxn][maxlg];
int w[maxn], ans[maxn];
int cnt1[maxn << 1], cnt2[maxn << 1];
int n, m;

void dfs_lca( int u, int p )
{
    dep[u] = dep[p] + 1, up[u][0] = p;
    for( int i = 1; i < maxlg; ++ i ) up[u][i] = up[up[u][i - 1]][i - 1];
    for( int v : adj[u] ) if( v != p ) dfs_lca( v, u );
}

int get_lca( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = maxlg - 1; i >= 0; -- i ) if( (diff >> i) & 1 ) u = up[u][i];
    if( u == v ) return u;
    for( int i = maxlg - 1; i >= 0; -- i ) if( up[u][i] != up[v][i] ) u = up[u][i], v = up[v][i];
    return up[u][0];
}

void dfs_solve( int u, int p )
{
    int upVal = w[u] + dep[u];
    int downVal = w[u] - dep[u] + maxn;

    int pre1 = cnt1[upVal];
    int pre2 = cnt2[downVal];

    for( auto &[opt, val] : add[u] )
    {
        if( opt == 0 ) cnt1[val] ++;
        else cnt2[val + maxn] ++;
    }
    for( auto &[opt, val] : del[u] )
    {
        if( opt == 0 ) cnt1[val] --;
        else cnt2[val + maxn] --;
    }

    for( int v : adj[u] ) if( v != p ) dfs_solve( v, u );

    int suf1 = cnt1[upVal];
    int suf2 = cnt2[downVal];

    ans[u] = suf1 - pre1 + suf2 - pre2;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for( int i = 1; i < n; ++ i )
    {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    dfs_lca( 1, 0 );

    for( int i = 1; i <= n; ++ i ) cin >> w[i];

    for( int i = 1; i <= m; ++ i )
    {
        int s, t, lca, dist;
        cin >> s >> t;
        lca = get_lca( s, t );
        dist = dep[s] + dep[t] - 2 * dep[lca];
        // 0 -> up | 1 -> down
        add[s].push_back({ 0, dep[s] });
        if( up[lca][0] != 0 ) del[up[lca][0]].push_back({ 0, dep[s] });
        add[t].push_back({ 1, dist - dep[t] });
        del[lca].push_back({ 1, dist - dep[t] });
    }

    dfs_solve( 1, 0 );

    for( int i = 1; i <= n; ++ i ) cout << ans[i] << " ";
    return 0;
}