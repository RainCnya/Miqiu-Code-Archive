#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;
const int maxm = 5e5 + 50;

vector< int > adj[maxn], dag[maxn];
stack< int > st;
int dfn[maxn], low[maxn], timer;
bool in_stack[maxn];
int scc[maxn], scc_cnt;
int indeg[maxn];
ll val[maxn], scc_val[maxn];
bool bar[maxn], scc_bar[maxn];
ll dist[maxn];
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
            in_stack[v] = 0;
            scc[v] = scc_cnt;
            scc_val[scc_cnt] += val[v];
            scc_bar[scc_cnt] |= bar[v];
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

    for( int i = 1; i <= n; ++ i ) cin >> val[i];

    int s, p;
    cin >> s >> p;
    
    for( int i = 1; i <= p; ++ i )
    {
        int b;
        cin >> b;
        bar[b] = 1;
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
            indeg[scc[v]] ++;
        }
    }

    memset( dist, -1, sizeof( dist ) );
    dist[scc[s]] = scc_val[scc[s]];

    queue< int > q;
    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( indeg[i] == 0 ) q.push( i );
    }

    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );
        for( int v : dag[u] )
        {
            if( dist[u] != -1 ) 
            {
                dist[v] = max( dist[v], dist[u] + scc_val[v] );
            }
            indeg[v] --;
            if( indeg[v] == 0 ) q.push( v );
        }
    }

    ll ans = 0;
    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( scc_bar[i] && dist[i] != -1 ) ans = max( ans, dist[i] );
    }
    
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}