#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const int maxm = 1e6 + 50;

struct Edge { int u, v; } edges[maxm];

vector< int > adj[maxn], scc_adj[maxn];
stack< int > st;
int dfn[maxn], low[maxn], timer;
bool in_stack[maxn];
int scc[maxn], scc_cnt, scc_size[maxn];
int n, m, mod;
int indeg[maxn];
ll f[maxn], dp[maxn];

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
            scc_size[scc_cnt] ++;
        } while( u != v );
    }
}

void solve( )
{
    cin >> n >> m >> mod;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        edges[i] = { u, v };
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v] = edges[i];
        if( scc[u] == scc[v] ) continue;
        scc_adj[scc[u]].push_back( scc[v] );
    }

    for( int i = 1; i <= scc_cnt; ++ i )
    {
        sort( scc_adj[i].begin( ), scc_adj[i].end( ) );
        scc_adj[i].erase( unique( scc_adj[i].begin( ), scc_adj[i].end( ) ), scc_adj[i].end( ) );
        for( int v : scc_adj[i] ) indeg[v] ++;
    }

    queue< int > q;

    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( indeg[i] == 0 ) 
        {
            q.push( i );
            dp[i] = 1;
            f[i] = scc_size[i];
        }
    }

    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );
        for( int v : scc_adj[u] )
        {
            indeg[v] --;
            if( f[u] + scc_size[v] > f[v] )
            {
                f[v] = f[u] + scc_size[v];
                dp[v] = dp[u];
            }
            else if( f[u] + scc_size[v] == f[v] )
            {
                dp[v] = ( dp[v] + dp[u] ) % mod;
            }
            if( indeg[v] == 0 ) q.push( v );
        }
    }

    ll ans_k = 0, ans_c = 0;
    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( f[i] > ans_k ) ans_k = f[i]; 
    }

    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( f[i] == ans_k ) ans_c = ( ans_c + dp[i] ) % mod;
    }

    cout << ans_k << '\n' << ans_c << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}