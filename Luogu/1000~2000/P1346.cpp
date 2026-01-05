#include<bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using ll = long long;

const int maxn = 100 + 5;
const int inf = 1e9;

int n, a, b;
vector<PII> adj[maxn];
int dist[maxn];

void dijkstra( int st )
{
    for( int i = 1; i <= n; ++ i )
        dist[i] = inf;
    dist[st] = 0;

    priority_queue< PII, vector<PII>, greater<PII> > pq;
    pq.push({ 0, st });

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( ); pq.pop( );
        if( d > dist[u] ) continue;

        for( auto& [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main( )
{	
    cin >> n >> a >> b;
    
    for( int i = 1; i <= n; ++ i )
    {
        int k;
        cin >> k;
        for( int j = 1; j <= k; ++ j )
        {
            int x;
            cin >> x;
            if( j == 1 ) adj[i].push_back({ x, 0 });
            else adj[i].push_back({ x, 1 });
        }
    }

    dijkstra( a );
    int ans = dist[b];
    
    if( ans == inf ) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}