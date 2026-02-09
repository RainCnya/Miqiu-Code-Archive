#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;
const int maxm = 5e4 + 50;

vector< int > adj[maxn];
int dfn[maxn], low[maxn], timer;
int scc[maxn], scc_cnt, scc_size[maxn];
bool in_stack[maxn];
stack< int > st;
int outd[maxn];
int n, m;

void tarjan( int u )
{
    dfn[u] = low[u] = ++ timer;
    st.push( u );
    in_stack[u] = true;

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

    if( dfn[u] == low[u] )
    {
        scc_cnt ++;
        int v;
        do {
            v = st.top( ); st.pop( );
            in_stack[v] = false;
            scc[v] = scc_cnt;
            scc_size[scc_cnt] ++;
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
            if( scc[u] != scc[v] ) outd[scc[u]] ++;
        }
    }

    int cnt = 0, ans = 0;
    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( outd[i] == 0 )
        {
            cnt ++;
            ans = scc_size[i];
        }
    }

    if( cnt == 1 ) cout << ans << '\n';
    else cout << 0 << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}