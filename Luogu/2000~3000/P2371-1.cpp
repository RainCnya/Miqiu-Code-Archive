#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;
const ll inf = 1e18;

struct State {
    int u; ll d;
    bool operator < ( const State &oth ) const { return d > oth.d; }
};

ll dist[maxn];
bool vis[maxn];
int a[15];
int n, mn;
ll l, r;

void dijkstra( int s )
{
    for( int i = 0; i < mn; ++ i ) dist[i] = inf;
    dist[s] = 0;

    priority_queue< State > pq;
    pq.push({ s, 0 });

    while( !pq.empty( ) )
    {
        auto [u, d] = pq.top( );
        pq.pop( );

        if( vis[u] ) continue;
        vis[u] = 1;

        for( int i = 1; i <= n; ++ i )
        {
            if( a[i] == mn ) continue;
            int v = ( u + a[i] ) % mn;
            if( dist[u] + a[i] < dist[v] )
            {
                dist[v] = dist[u] + a[i];
                pq.push({ v, dist[v] });
            }
        }
    }
}

ll query( ll x )
{
    ll res = 0;
    for( int i = 0; i < mn; ++ i )
    {
        if( dist[i] <= x )
            res += ( x - dist[i] ) / mn + 1;
    }
    return res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;

    mn = 2e9;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( a[i] > 0 ) mn = min( mn, a[i] );
    }

    dijkstra( 0 );

    cout << query( r ) - query( l - 1 ) << '\n';
    
    return 0;
}