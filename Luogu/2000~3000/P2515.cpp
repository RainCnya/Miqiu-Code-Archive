#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const int maxm = 500 + 5;

vector< int > adj[maxn], dag[maxn];
stack< int > st;
int dfn[maxn], low[maxn], timer;
bool in_stack[maxn];
int scc[maxn], scc_cnt;
int fa[maxn], indeg[maxn];
ll val[maxn], scc_val[maxn];
ll wei[maxn], scc_wei[maxn];
ll dp[maxn][maxm];
int n, m;

void dfs( int u )
{
    for( int j = scc_wei[u]; j <= m; ++ j )
    {
        dp[u][j] = scc_val[u];
    }

    for( int v : dag[u] )
    {
        dfs( v );
        for( int j = m; j >= scc_wei[u]; -- j )
        {
            for( int k = 0; k <= j - scc_wei[u]; ++ k )
            {
                dp[u][j] = max( dp[u][j], dp[u][j - k] + dp[v][k] );
            }
        }
    }
}

void tarjan( int u )
{
    dfn[u] = low[u] = ++ timer;
    st.push( u );
    in_stack[u] = 1;
    
    for( int v : adj[u] )
    {
        if( !dfn[v] )
        {
            tarjan( v );
            low[u] = min( low[u], low[v] );
        }
        else if( in_stack[v] )
        {
            low[u] = min( low[u], dfn[v] ); 
        }
    }

    if( low[u] == dfn[u] )
    {
        scc_cnt ++;
        int v;
        do {
            v = st.top( ); st.pop( );
            in_stack[v] = 0;
            scc[v] = scc_cnt;
            scc_val[scc_cnt] += val[v];
            scc_wei[scc_cnt] += wei[v];
        } while( v != u );
    }
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) cin >> wei[i];
    for( int i = 1; i <= n; ++ i ) cin >> val[i];
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> fa[i];
        if( fa[i] == 0 ) continue;
        adj[fa[i]].push_back( i );
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    for( int u = 1; u <= n; ++ u )
    {
        int v = fa[u];
        if( v == 0 || scc[u] == scc[v] ) continue; 
        dag[scc[v]].push_back( scc[u] );
        indeg[scc[u]] ++;
    }

    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( indeg[i] == 0 ) dag[0].push_back( i );
    }

    scc_wei[0] = scc_val[0] = 0;
    dfs( 0 );

    cout << dp[0][m] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}