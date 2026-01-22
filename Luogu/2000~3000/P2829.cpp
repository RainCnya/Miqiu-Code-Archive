#include<bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

const int maxn = 5e3 + 50;
const int inf = 0x3f3f3f3f;

bool mat[maxn][maxn];
int deg[maxn];

vector<PII> adj[maxn];
int dist[maxn][2];
int n, m, k;

void dijkstra( int st )
{
    memset( dist, 0x3f, sizeof( dist ) );
    dist[1][0] = 0;

    priority_queue< PII, vector<PII>, greater<PII> > pq;
    pq.push({ 0, 1 });

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
        pq.pop( );

        if( d > dist[u][1] ) continue;
        for( auto [v, w] : adj[u] )
        {
            if( v != 1 && v != n && deg[v] < k ) continue;
            int nd = d + w;

            if( nd < dist[v][0] )
            {
                if( dist[v][0] != inf )
                {
                    dist[v][1] = dist[v][0];
                    pq.push({ dist[v][1], v });
                }
                dist[v][0] = nd;
                pq.push({ dist[v][0], v });
            }
            else if( dist[v][0] < nd && nd < dist[v][1] )
            {
                dist[v][1] = nd;
                pq.push({ dist[v][1], v });
            }
        }
    }   
}

int main( )
{	
    cin >> n >> m >> k;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
        if( !mat[u][v] )
        {
            deg[u] ++, deg[v] ++;
            mat[u][v] = mat[v][u] = 1;
        }
    }

    dijkstra( 1 );

    if( dist[n][1] == inf )
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << dist[n][1] << '\n';
    }

    return 0;
}