#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using PLI = pair< ll, int >;

const int maxn = 1005;
const int max1 = 1e6 + 5;
const int max2 = 4e6 + 5;
const ll inf = 1e18;

int to[max2];
ll cost[max2];
int nxt[max2];

int head[max1];
int idx = 0;

int mat[maxn][maxn];
ll dis[maxn][maxn][3];
int n, m, a, b, c;

bool check( int i, int j ) {
    return 1 <= i && i <= n && 1 <= j && j <= m;
}

int calc( int i, int j ) {
    return ( i - 1 ) * m + j;
}

void addEdge( int ux, int uy, int vx, int vy )
{
    int u = calc( ux, uy );
    int v = calc( vx, vy );
    ll c = mat[vx][vy];

    idx ++;
    to[idx] = v;
    cost[idx] = c;
    nxt[idx] = head[u];
    head[u] = idx;
}

void build( )
{
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            if( i < n )
            {
                int vi = i + 1;
                int vj = j;
                addEdge( vi, vj, i, j );
                addEdge( i, j, vi, vj );
            }
            if( j < m )
            {
                int vi = i;
                int vj = j + 1;
                addEdge( vi, vj, i, j );
                addEdge( i, j, vi, vj );
            }
        }
    }
}

void dijkstra( int s, int k )
{
    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= m; ++ j )
            dis[i][j][k] = inf;

    priority_queue< PLI, vector<PLI>, greater<PLI> > pq;
    
    int sx = ( s - 1 ) / m + 1;
    int sy = ( s - 1 ) % m + 1;

    dis[sx][sy][k] = mat[sx][sy];
    pq.push({ dis[sx][sy][k], s });
    
    while( !pq.empty( ) )
    {
        auto [d, u] = pq.top( ); pq.pop( );
        int ux = ( u - 1 ) / m + 1;
        int uy = ( u - 1 ) % m + 1;
        if( d > dis[ux][uy][k] ) continue;

        for( int i = head[u]; i; i = nxt[i] )
        {
            int v = to[i];
            ll c = cost[i];
            int vx = ( v - 1 ) / m + 1;
            int vy = ( v - 1 ) % m + 1;
            if( dis[ux][uy][k] + c < dis[vx][vy][k] )
            {
                dis[vx][vy][k] = dis[ux][uy][k] + c;
                pq.push({ dis[vx][vy][k], v });
            }
        }
    }
}

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> a >> b >> c;
    
    for( int i = n; i >= 1; -- i )
        for( int j = 1; j <= m; ++ j )
            cin >> mat[i][j];

    build( );

    dijkstra( calc( n, a ), 0 );
    dijkstra( calc( 1, b ), 1 );
    dijkstra( calc( 1, c ), 2 );

    ll ans = inf;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            ll d1 = dis[i][j][0];
            ll d2 = dis[i][j][1];
            ll d3 = dis[i][j][2];
            if( d1 != inf && d2 != inf && d3 != inf )
            {
                ll cost = d1 + d2 + d3 - 2ll * mat[i][j];
                ans = min( ans, cost );
            }
        }
    }

    cout << ans << '\n';
    return 0;
}