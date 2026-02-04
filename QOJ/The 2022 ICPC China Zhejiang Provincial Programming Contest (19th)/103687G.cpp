#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
const double inf = 1e18;

struct Point {
    ll x, y;
} p[maxn];

double dist[maxn];
bool vis[maxn];
int n;
ll v1, v2;

double distcalc( Point a, Point b )
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

double timecalc( int u, int v )
{
    double d = distcalc( p[u], p[v] );
    if( u == 0 ) return d / v1;
    if( d <= 3 * v2 ) return d / v2;
    return 3 + ( d - 3 * v2 ) / v1;
}

void dijkstra( )
{
    for( int i = 0; i <= n + 1; ++ i )
    {
        dist[i] = inf;
        vis[i] = 0;
    }

    dist[0] = 0;
    for( int i = 0; i <= n; ++ i )
    {
        int u = -1;
        for( int j = 0; j <= n + 1; ++ j )
        {
            if( !vis[j] && ( u == -1 || dist[j] < dist[u] ) )
            {
                u = j;
            }
        }
        
        if( u == -1 || dist[u] == inf ) break;
        vis[u] = 1;
        if( u == n + 1 ) break;

        for( int v = 0; v <= n + 1; ++ v )
        {
            if( vis[v] ) continue;
            double time = timecalc( u, v );
            dist[v] = min( dist[v], dist[u] + time );
        }
    }
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> p[i].x >> p[i].y;

    cin >> p[0].x >> p[0].y >> p[n + 1].x >> p[n + 1].y;
    cin >> v1 >> v2;

    dijkstra( );

    cout << fixed << setprecision( 12 ) << dist[n + 1] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}