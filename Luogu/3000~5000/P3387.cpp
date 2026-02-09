#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;

vector< int > adj[maxn], dag[maxn];
int indeg[maxn];
int val[maxn];
int dp[maxn];
int n, m;

int dfn[maxn], low[maxn], timer;
int scc[maxn], scc_cnt, scc_val[maxn];
stack< int > st;
bool in_stack[maxn];


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
            in_stack[v] = false;
            scc[v] = scc_cnt;
            scc_val[scc_cnt] += val[v];
        } while( v != u );
    }

}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) cin >> val[i];

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    for( int u = 1; u <= n; ++ u )
    {
        for( int v : adj[u] )
        {
            if( scc[u] != scc[v] )
            {
                dag[scc[u]].push_back( scc[v] );
                indeg[scc[v]] ++;
            }
        }
    }

    queue< int > q;
    for( int i = 1; i <= scc_cnt; ++ i )
    {
        dp[i] = scc_val[i];
        if( indeg[i] == 0 ) q.push( i );
    }

    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );
        for( int v : dag[u] )
        {
            dp[v] = max( dp[v], dp[u] + scc_val[v] );
            indeg[v]--;
            if( indeg[v] == 0 ) q.push( v );
        }
    }

    int ans = 0;
    for( int i = 1; i <= scc_cnt; ++ i ) ans = max( ans, dp[i] );
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}