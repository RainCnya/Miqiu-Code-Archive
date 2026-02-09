#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 400 + 5;
const int maxm = 40000 + 5;
const ll inf = 1e18;

struct Edge { int v; ll w; };
vector< Edge > adj[maxn * 4];
map< string, int > id;

struct State {
    int u; ll d;
    bool operator < ( const State &oth ) const { return d > oth.d; }
};

ll dist[maxn * 4];
ll c[maxn];
int n, m;
string s;

int get_trans( string opt )
{
    if( opt == "AIR" ) return 0;
    if( opt == "SEA" ) return 1;
    if( opt == "RAIL" ) return 2;
    if( opt == "TRUCK" ) return 3;
    return -1;
}

void dijkstra( int start )
{
    for( int i = 1; i <= n * 4; ++ i ) dist[i] = inf;

    priority_queue< State > pq;

    for( int i = 0; i < 4; ++ i )
    {
        pq.push({ start + i * n, 0 });
        dist[start + i * n] = 0;
    }

    while( !pq.empty( ) )
    {
        auto [u, d] = pq.top( ); pq.pop( );
        if( d > dist[u] ) continue;

        for( auto &[v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                pq.push({ v, dist[v] });
            }
        }
    }
}

void solve( )
{
    cin >> n;
    
    id.clear( );

    for( int i = 1; i <= n; ++ i )
    {
        string city;
        ll cost;
        cin >> city >> c[i];
        id[city] = i;
    }

    for( int i = 1; i <= n * 4; ++ i ) adj[i].clear( );

    for( int k = 1; k <= n; ++ k )
    {
        for( int i = 0; i < 4; ++ i )
        {
            for( int j = 0; j < 4; ++ j )
            {
                if( i == j ) continue;
                adj[k + i * n].push_back({ k + j * n, c[k] });
            }
        }
    }

    cin >> m;
    for( int i = 1; i <= m; ++ i )
    {
        string u, v, opt; ll w;
        cin >> u >> v >> opt >> w;
        int x = id[u], y = id[v];
        int k = get_trans( opt );
        adj[x + k * n].push_back({ y + k * n, w });
        adj[y + k * n].push_back({ x + k * n, w });
    }

    string st_name, ed_name;
    cin >> st_name >> ed_name;
    int st = id[st_name], ed = id[ed_name];

    dijkstra( st );
    
    ll ans = inf;
    for( int i = 0; i < 4; ++ i ) ans = min( ans, dist[ed + i * n] );

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}