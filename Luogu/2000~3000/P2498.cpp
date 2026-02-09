#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;

struct Point { int x, y; } p[maxn];

struct Edge {
    int u, v; double w;
    bool operator < ( const Edge &oth ) const { return w < oth.w; }
};

vector<Edge> edges;
int cnt_edges;
int fa[maxn];
int n, row, line;

int find( int x )
{
    if( x == fa[x] ) return fa[x];
    else return fa[x] = find( fa[x] );
}

double get_dist( Point a, Point b )
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}

void solve( )
{
    cin >> n >> row >> line;
    for( int i = 1; i <= n; ++ i ) cin >> p[i].x >> p[i].y;
    p[0] = { 1, line };
    p[n + 1] = { row, 1 };
    for( int i = 0; i <= n + 1; ++ i ) fa[i] = i;

    edges.reserve( n * n / 2 + 2 * n + 5 );
    for( int i = 1; i <= n; ++ i )
    {
        double distA = min( p[i].x - p[0].x, p[0].y - p[i].y );
        edges.push_back({ i, 0, distA } );
        double distB = min( p[n + 1].x - p[i].x, p[i].y - p[n + 1].y );
        edges.push_back( { i, n + 1, distB } );

        for( int j = 1; j < i; ++ j )
        {
            double dist = get_dist( p[i], p[j] );
            edges.push_back({ i, j, dist / 2.0 });
        }
    }

    sort( edges.begin( ), edges.end( ) );

    double ans = 0;
    for( auto [u, v, w] : edges )
    {
        int ru = find( u ), rv = find( v );

        if( ru != rv ) fa[ru] = rv;

        if( find( 0 ) == find( n + 1 ) )
        {
            ans = w;
            break;
        }
    }

    cout << fixed << setprecision(2) << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}