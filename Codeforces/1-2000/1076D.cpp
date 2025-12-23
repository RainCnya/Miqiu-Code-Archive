#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLI = pair<ll, int>;

const int maxn = 3e5 + 50;
const ll inf = 1e18;

struct Edge {
    int to, id;
    ll w;
};

vector<Edge> adj[maxn];
vector<PII> tadj[maxn];
PII pre[maxn];

ll dis[maxn];
bool vis[maxn];
int n, m, k;

void dijkstra( )
{
    for( int i = 1; i <= n; ++ i )
    {
        dis[i] = inf, vis[i] = 0;
    }
    dis[1] = 0;

    priority_queue< PLI, vector<PLI>, greater<PLI> > pq;
    pq.push({ 0, 1 });

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
        pq.pop( );

        if( vis[u] ) continue;
        vis[u] = 1;

        for( auto& [v, id, w] : adj[u] )
        {
            if( dis[u] + w < dis[v] )
            {
                dis[v] = dis[u] + w;
                pre[v] = { u, id };
                pq.push({ dis[v], v });
            }
        }
    }
}

void build( )
{
    for( int i = 2; i <= n; ++ i )
    {
        auto [u, id] = pre[i];
        tadj[u].push_back({ i, id });
    }
}

void bfs( )
{
    vector<int> ans;
    queue<int> q;
    q.push( 1 );

    while( !q.empty( ) )
    {
        if( ans.size( ) >= k ) break;

        int u = q.front( );
        q.pop( );

        for( auto& [v, id] : tadj[u] )
        {
            ans.push_back( id );
            if( ans.size( ) >= k ) break;
            q.push( v );
        }
    }

    cout << ans.size( ) << '\n';
    for( int x : ans )
        cout << x << " ";
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, i, w });
        adj[v].push_back({ u, i, w });
    }

    dijkstra( );
    build( );
    bfs( );

    return 0;
}