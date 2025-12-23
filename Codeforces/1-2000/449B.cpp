#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e18;
const int N = 1e5 + 5;

int n, m, k;
struct node{
    int to;
    long long w;
};
vector<node> adj[N];
long long dist[N];
int ind[N];

void dijkstra( )
{
    for( int i = 1; i <= n; ++ i )  
        dist[i] = inf;
    priority_queue<pair<long long, int>> pq;
    pq.push( {0, 1} );
    dist[1] = 0;
    while( !pq.empty( ) )
    {
        long long d = -pq.top( ).first; 
        int u = pq.top( ).second;
        pq.pop( );
        if( d > dist[u] ) continue;
        for( auto& [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                pq.push( { -dist[v], v } );
            }
        }
    }
}

int main( )
{    
    scanf("%d%d%d", &n, &m, &k);
    for( int i = 1; i <= m; ++ i )
    {
        int u, v; 
        long long x;
        scanf("%d %d %lld", &u, &v, &x);
        adj[u].push_back( {v, x} );
        adj[v].push_back( {u, x} );
    }
    vector<pair<int, long long>>railways;
    for( int i = 1; i <= k; ++ i )
    {
        int s;
        long long y;
        scanf("%d %lld", &s, &y);
        adj[1].push_back( {s, y} );
        adj[s].push_back( {1, y} );
        railways.push_back( {s, y} );
    }
    dijkstra( );
    for( int u = 1; u <= n; ++ u )
    {
        for( auto& edge : adj[u] )
        {
            int v = edge.to;
            long long w = edge.w;
            if( dist[u] + w == dist[v] )
                ind[v] ++;
        }
    }
    int ans = 0;
    for( auto& rail : railways )
    {
        int s = rail.first;
        long long y = rail.second;
        if( dist[s] < y )
            ans ++;
        else if( dist[s] == y )
        {
            if( ind[s] > 1 )
            {
                ans ++;
                ind[s] --;
            }
        }
    }
    cout << ans << endl;
    return 0;
}