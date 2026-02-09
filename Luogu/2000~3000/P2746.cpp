#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;

vector< int > adj[maxn];
stack< int > st;
int dfn[maxn], low[maxn], timer;
int scc[maxn], scc_cnt;
bool in_stack[maxn];
int indeg[maxn], outdeg[maxn];
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
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        int x;
        while( cin >> x && x != 0 ) adj[i].push_back( x );
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    if( scc_cnt == 1 )
    {
        cout << '1' << '\n' << 0 << '\n';
        return;
    }

    for( int u = 1; u <= n; ++ u )
    {
        for( int v : adj[u] )
        {
            if( scc[u] != scc[v] )
            {
                indeg[scc[v]] ++;
                outdeg[scc[u]] ++;
            }
        }
    }

    int in0 = 0, out0 = 0;
    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( indeg[i] == 0 ) in0 ++;
        if( outdeg[i] == 0 ) out0 ++;
    }

    cout << in0 << '\n' << max( in0, out0 ) << '\n';

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}