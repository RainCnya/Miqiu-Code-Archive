#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLI = pair<ll, int>;

const int maxn = 1e5 + 50;
const ll inf = 1e18;

vector<PII> adj[maxn];
vector<PII> radj[maxn];
int ks[maxn];
int n, m, k;

ll d1[maxn], d2[maxn];
int c1[maxn], c2[maxn];

void dijkstra( int type )
{
    ll *dist; int *color; vector<PII> *gragh;
    if( type == 0 ) dist = d1, color = c1, gragh = adj;
    else dist = d2, color = c2, gragh = radj;

    for( int i = 1; i <= n; ++ i )
    {
        dist[i] = inf;
        color[i] = 0;
    } 

    priority_queue< PLI, vector<PLI>, greater<PLI> > pq;
    for( int i = 1; i <= k; ++ i )
    {
        int k = ks[i];
        dist[k] = 0;
        color[k] = k;
        pq.push({ 0, k });
    }

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
        pq.pop( );
        if( d > dist[u] ) continue;

        for( auto [v, w] : gragh[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                color[v] = color[u];
                pq.push({ dist[v], v });
            }
        }
    }

}

void solve( )
{
    cin >> n >> m >> k;

    for( int i = 1; i <= n; ++ i )
    {
        adj[i].clear( );
        radj[i].clear( );
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        if( u != v )
        {
            adj[u].push_back({ v, w });
            radj[v].push_back({ u, w });
        }
    }

    for( int i = 1; i <= k; ++ i )
    {
        cin >> ks[i];
    }

    dijkstra( 0 );
    dijkstra( 1 );

    ll ans = inf;

    for( int u = 1; u <= n; ++ u )
    {
        for( auto& [v, w] : adj[u] )
        {
            if( c1[u] && c2[u] && c1[u] != c2[v] )
                ans = min( ans, d1[u] + w + d2[v] );
        }
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}