#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLI = pair<ll, int>;

const int maxn = 5e5 + 50;
const ll inf = 1e18;

int n, mn;
int a[15];
bool vis[maxn];
ll l, r;
ll dist[maxn];

void dijkstra( )
{
    for( int i = 0; i < mn; ++ i )
        dist[i] = inf;
    dist[0] = 0;

    priority_queue< PLI, vector<PLI>, greater<PLI> > pq;
    pq.push({ 0, 0 });

    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( );
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
                pq.push({ dist[v], v });
            }
        }
    }
}

ll query( ll x )
{
    ll ans = 0;
    for( int i = 0; i < mn; ++ i )
    {
        if( dist[i] <= x )
            ans += ( x - dist[i] ) / mn + 1;
    }
    return ans;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;

    mn = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( a[i] == 0 ) continue;
        if( mn == 0 || a[i] < mn ) mn = a[i];
    }

    if( mn == 0 )
    {
        cout << 0 << '\n';
        return 0;
    }

    dijkstra( );

    cout << query( r ) - query( l - 1 ) << '\n';
    
    return 0;
}