#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;

vector< int > adj[maxn];
int w[maxn];
int n, m, k;
bool loop[maxn];

int dfn[maxn], low[maxn], timer;
int scc[maxn], scc_cnt, scc_size[maxn];
bool in_stack[maxn];
stack< int > st;

int scc_min[maxn];
bool scc_loop[maxn];

int indeg[maxn];
int cnt[1005];

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
        scc_min[scc_cnt] = 1001;
        int v;
        do {
            v = st.top( ); st.pop( );
            in_stack[v] = false;
            scc[v] = scc_cnt;
            scc_size[scc_cnt] ++;
            scc_loop[scc_cnt] |= loop[v];
            scc_min[scc_cnt] = min( scc_min[scc_cnt], w[v] );
        } while( v != u );
    }

}

void solve( )
{
    cin >> n >> m >> k;

    for( int i = 1; i <= n; ++ i ) cin >> w[i];

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        if( u == v ) loop[u] = 1;
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
            indeg[scc[v]] ++;
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        int id = scc[i];
        if( indeg[id] > 0 || scc_loop[id] ) cnt[w[i]] ++;
        else if( scc_size[id] > 1 )
        {
            if( w[i] > scc_min[id] ) 
            {
                cnt[w[i]] ++;
            }
            else 
            {
                if( scc_min[id] == -1 ) cnt[w[i]] ++;
                else scc_min[id] = -1;
            }
        }
    }

    ll ans = 0;
    for( int i = 1000; i >= 0 && k >= 0; -- i )
    {
        int t = min( k, cnt[i] );
        ans += (ll)t * i;
        k -= t;
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