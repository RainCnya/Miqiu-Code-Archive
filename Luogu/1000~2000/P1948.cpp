#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 50;
const ll inf = 1e18;

struct Edge { int v, w; };
vector< Edge > adj[maxn];
int n, p, k;

ll dist[maxn];


bool check( ll mid )
{
    for( int i = 1; i <= n; ++ i ) dist[i] = inf;
    dist[1] = 0;

    queue< int > q;
    q.push(1);
    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );
        
        for( auto [v, w] : adj[u] )
        {
            if( w <= mid )
            {
                if( dist[u] < dist[v] )
                {
                    dist[v] = dist[u];
                    q.push(v);
                }
            }
            else
            {
                if( dist[u] + 1 < dist[v] )
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    return dist[n] <= k;
}

void solve( )
{
    cin >> n >> p >> k;
    for( int i = 1; i <= p; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll l = 0, r = 1e9, ans = -1;
    while( l <= r )
    {
        ll mid = (l + r) >> 1;
        if( check( mid ) ) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}