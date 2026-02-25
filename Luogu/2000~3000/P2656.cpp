#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 8e4 + 5;

struct Edge { int v, w, coe; };
vector< Edge > adj[maxn];
int dfn[maxn], low[maxn], timer;
int scc[maxn], scc_cnt;
ll scc_val[maxn];
bool in_stk[maxn];
int indeg[maxn];
stack< int > stk;
int n, m, s;

ll calc( int w, int coe )
{
    ll sum = 0;
    while( w > 0 ) {
        sum += w;
        w = w * coe / 10;
    }
    return sum;
}

void tarjan( int u )
{
    dfn[u] = low[u] = ++ timer;
    stk.push( u ); in_stk[u] = 1;
    
    for( auto [v, w, coe] : adj[u] )
    {
        if( !dfn[v] )
        {
            tarjan( v );
            low[u] = min( low[u], low[v] );
        }
        else if( in_stk[v] )
        {
            low[u] = min( low[u], dfn[v] );
        }
    }
    
    if( dfn[u] == low[u] )
    {
        scc_cnt ++;
        int v;
        do {
            v = stk.top( ); stk.pop( );
            in_stk[v] = 0;
            scc[v] = scc_cnt;
        } while( v != u );
    }
}

struct Edge2 { int v; ll w; };
vector< Edge2 > dag[maxn];
ll dist[maxn];

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w; double _c;
        cin >> u >> v >> w >> _c;
        int c = (int)( _c * 10 );
        adj[u].push_back({ v, w, c });
    }

    cin >> s;

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    for( int u = 1; u <= n; ++ u )
    {
        for( auto [v, w, coe] : adj[u] )
        {
            if( scc[u] == scc[v] )
            {
                scc_val[scc[u]] += calc( w, coe );
            }
            else
            {
                dag[scc[u]].push_back({ scc[v], (ll)w });
                indeg[scc[v]] ++;
            }
        }
    }

    for( int i = 1; i <= scc_cnt; ++ i ) dist[i] = -1;
    dist[scc[s]] = scc_val[scc[s]];

    queue< int > q;
    for( int i = 1; i <= scc_cnt; ++ i )
        if( indeg[i] == 0 ) q.push( i );

    ll ans = 0;
    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );
        ans = max( ans, dist[u] );

        for( auto [v, w] : dag[u] )
        {
            if( dist[u] != -1 ) dist[v] = max( dist[v], dist[u] + w + scc_val[v] );
            if( -- indeg[v] == 0 ) q.push( v );
        }
    }
    
    cout << ans << '\n';
    return 0;
}
