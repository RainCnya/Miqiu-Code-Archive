#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;
const int maxm = 10000 + 5;
const double inf = 1e18;

struct Edge {
    int to;
    double weight;
};

vector< Edge > adj[maxn];
double dist[maxn];
bool vis[maxn];
int n, m;

bool has_neg_cycle( int u, double mid )
{
    vis[u] = true;
    for( auto [v, w] : adj[u] )
    {
        if( dist[v] > dist[u] + w - mid )
        {
            if( vis[v] ) return true;
            dist[v] = dist[u] + w - mid;
            if( has_neg_cycle( v, mid ) ) return true;
        }
    }
    vis[u] = false;
    return false;
}

bool check( double mid )
{
    for( int i = 1; i <= n; ++ i ) 
    {
        dist[i] = 0;
        vis[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( has_neg_cycle( i, mid ) ) return 1;
    }
    return 0;
}

void solve( )
{
    cin >> n >> m;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        double w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
    }

    double l = -1e7, r = 1e7, ans = 0;
    for( int i = 1; i <= 100; ++ i )
    {
        double mid = ( l + r ) / 2.0;
        if( check( mid ) ) ans = mid, r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(8) << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- ) solve( );
    return 0;
}