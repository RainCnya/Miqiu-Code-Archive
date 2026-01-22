#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int maxn = 3e5 + 50;
const int maxlg = 20;
// cosnt
vector<int> adj[maxn];
int fa[maxn][maxlg];
int dep[maxn];
// lca
int n, m; 
int w[maxn];
int ans[maxn];
// std
vector< PII > add[maxn];
vector< PII > del[maxn];
int c1[maxn << 1];
int c2[maxn << 1];
// calc

void dfs( int u, int father )
{
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    for( int v : adj[u] )
        if( v != father )
            dfs( v, u );
    return;
}

void lcaInit( )
{
    dfs( 1, 0 );
    for( int j = 1; j < maxlg; ++ j )
        for( int i = 1; i <= n; ++ i )
            fa[i][j] = fa[ fa[i][j-1] ][j-1];
    return;
}

int getlca( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = 0; (1 << i) <= diff; ++ i )
    {
        if( (1 << i) & diff )
            u = fa[u][i];
    }
    if( u == v ) return u;
    for( int i = maxlg - 1; i >= 0; -- i )
    {
        if( fa[u][i] != fa[v][i] )
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void dfsSolve( int u )
{
    int upVal = w[u] + dep[u];
    int dnVal = w[u] - dep[u] + maxn;
    
    int pre1 = 0;
    if( 0 <= upVal && upVal < maxn << 1 )
        pre1 = c1[upVal];
    
    int pre2 = 0;
    if( 0 <= dnVal && dnVal < maxn << 1 )
        pre2 = c2[dnVal];
    
    for( auto p : add[u] )
    {
        if( p.first == 0 ) c1[p.second] ++;
        else c2[p.second + maxn] ++;
    }
    for( auto p : del[u] )
    {
        if( p.first == 0 ) c1[p.second] --;
        else c2[p.second + maxn] --;
    }

    for( int v : adj[u] )
    {
        if( v != fa[u][0] )
            dfsSolve( v );
    }

    int res1 = 0;
    if( 0 <= upVal && upVal < maxn << 1 )
        res1 = c1[upVal];
    
    int res2 =0;
    if( 0 <= dnVal && dnVal < maxn << 1 )
        res2 = c2[dnVal];

    ans[u] = (res1 - pre1) + (res2 - pre2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }   
    
    for( int i = 1; i <= n; ++ i )
        cin >> w[i];

    lcaInit( );

    for( int i = 1; i <= m; ++ i )
    {
        int s, t;
        cin >> s >> t;
        int lca = getlca( s, t );

        int upVal = dep[s];
        add[s].push_back({ 0, upVal });
        int pa = fa[lca][0];
        if( pa != 0 )
            del[pa].push_back({ 0, upVal });

        int dnVal = dep[s] - 2 * dep[lca];
        add[t].push_back({ 1, dnVal });
        del[lca].push_back({ 1, dnVal });
    }

    dfsSolve( 1 );

    for( int i = 1; i <= n; ++ i ) {
        cout << ans[i];
        if( i != n ) cout << " ";
    }
        
    return 0;
}