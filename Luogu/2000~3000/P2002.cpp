#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const int maxm = 5e5 + 50;

vector< int > adj[maxn], dag[maxn];
stack< int > st;
int dfn[maxn], low[maxn], timer;
int scc[maxn], scc_cnt;
bool in_stack[maxn];
int indeg[maxn];
int n, m;

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
        } while( v != u );
    }

}

void solve( )
{
    cin >> n >> m;

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
            if( scc[u] == scc[v] ) continue;
            dag[scc[u]].push_back( scc[v] );
        }
    }

    for( int i = 1; i <= scc_cnt; ++ i )
    {
        sort( dag[i].begin( ), dag[i].end( ) );
        dag[i].erase( unique( dag[i].begin( ), dag[i].end( ) ), dag[i].end( ) );
        for( int v : dag[i] ) indeg[v] ++;
    }

    int ans = 0;
    for( int i = 1; i <= scc_cnt; ++ i ) if( indeg[i] == 0 ) ans ++;
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}