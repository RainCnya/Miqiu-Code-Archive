#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;
const int maxlg = 20;

struct Edge { int u, v; };

vector< int > adj[maxn];
int sz[maxn], f[maxn];
int son1[maxn], son2[maxn];
int down[maxn][maxlg], fa[maxn];
int bel[maxn];
int n, rt;
ll ans;

void get_root( int u, int p )
{
    sz[u] = 1;
    f[u] = 0;

    for( int v : adj[u] )
    {
        if( v == p ) continue;
        get_root( v, u );
        sz[u] += sz[v];
        f[u] = max( f[u], sz[v] );
    }

    f[u] = max( f[u], n - sz[u] );
    if( f[u] < f[rt] ) rt = u;
}

void dfs( int u, int p, int top )
{
    sz[u] = 1;
    fa[u] = p;
    bel[u] = top;
    son1[u] = son2[u] = 0;

    for( int v : adj[u] )
    {
        if( v == p ) continue;

        if( u == rt ) dfs( v, u, v );
        else dfs( v, u, top );
        sz[u] += sz[v];

        if( sz[v] > sz[son1[u]] ) son2[u] = son1[u], son1[u] = v;
        else if( sz[v] > sz[son2[u]] ) son2[u] = v;
    }
    down[u][0] = son1[u];
    for( int i = 1; i < maxlg; ++ i ) down[u][i] = down[down[u][i - 1]][i - 1];
}

int check( int u, int sum, int ms )
{
    return u * ( max( ms, sum - sz[u] ) <= sum / 2 );
}

void calc( int st, int sum, int del )
{

    int son = son1[st];
    if( st == rt && son1[st] == del ) son = son2[st];

    ans += check( st, sum, sz[son] );
    
    if( son == 0 || sz[son] < ( sum + 1 ) / 2 ) return;

    int cur = son;
    for( int i = maxlg - 1; i >= 0; -- i )
    {
        int nxt = down[cur][i];
        if( nxt && sz[nxt] >= ( sum + 1 ) / 2 ) cur = nxt;
    }

    ans += check( cur, sum, sz[son1[cur]] );
    if( cur != son ) ans += check( fa[cur], sum, sz[son1[fa[cur]]] );
}

void solve( )
{
    cin >> n;

    ans = 0;
    for( int i = 1; i <= n; ++ i ) adj[i].clear( );

    vector< Edge > edges;
    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
        edges.push_back( { u, v } );
    }

    rt = 0; f[0] = n + 1;
    get_root( 1, 0 );
    dfs( rt, 0, 0 );

    for( auto [u, v] : edges )
    {
        if( fa[v] != u ) swap( u, v );
        calc( v, sz[v] , 0 );
        calc( rt, n -  sz[v], bel[v] );
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while( T -- ) solve( );
    return 0;
}