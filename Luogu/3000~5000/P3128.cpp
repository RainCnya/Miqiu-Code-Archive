#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 5e4 + 50;
const int maxlg = 20;

int n, k;
int ans = -inf;
int dif[maxn];
int sum[maxn];
int dep[maxn];
int fa[maxn][maxlg];
vector<int> adj[maxn];

void dfs( int u, int father )
{
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    for( int v : adj[u] )
    {
        if( v != father )
            dfs( v, u );
    }
    return ;
}

void stInit( )
{
    for( int j = 1; j < maxlg; ++ j )
        for( int i = 1; i <= n; ++ i )
            fa[i][j] = fa[ fa[i][j-1] ][j-1];
    return ;
}

int getlca( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = 0; (1 << i) <= diff; ++ i )
    {
        if( (1 << i ) & diff )
            u = fa[u][i];
    }
    if( u == v ) return u;
    for( int i = maxlg - 1 ; i >= 0; -- i )
    {
        if( fa[u][i] != fa[v][i] )
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void getsum( int u, int father )
{
    sum[u] = dif[u];
    for( int v : adj[u] )
    {
        if( v != father )
        {
            getsum( v, u );
            sum[u] += sum[v];
        }
    }
    ans = max( ans, sum[u] );
}

int main() {
    cin >> n >> k;

    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v;   cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }
    
    dfs( 1, 0 );
    stInit( );

    for( int i = 1; i <= k; ++ i )
    {
        int s, t;   cin >> s >> t;
        int rt = getlca( s, t );
        dif[s] ++, dif[t] ++;
        dif[rt] --, dif[ fa[rt][0] ] --;
    }
    getsum( 1, 0 );
    cout << ans << '\n';
    return 0;
}