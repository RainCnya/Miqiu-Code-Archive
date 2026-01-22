#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int maxn = 1e6 + 50;
const int mod = 100003;

vector<int> adj[maxn];
int dist[maxn];
int f[maxn];
int n, m;

void dijkstra( )
{
    memset( dist, 127, sizeof( dist ) );
    dist[1] = 0;
    f[1] = 1;

    priority_queue< PII, vector<PII>, greater<PII> > pq;
    pq.push({ 0, 1 });

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
        pq.pop( );
        if( d > dist[u] ) continue;

        for( int v : adj[u] )
        {
            if( dist[u] + 1 == dist[v] )
            {
                f[v] = ( f[v] + f[u] ) % mod;
            }
            if( dist[u] + 1 < dist[v] )
            {
                dist[v] = dist[u] + 1;
                f[v] = f[u];
                pq.push({ dist[v], v });
            }
        }
    }
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    dijkstra( );
    for( int i = 1; i <= n; ++ i )
    {
        cout << f[i] << '\n';
    }
    return 0;
}