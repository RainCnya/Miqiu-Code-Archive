#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int maxn = 3e3 + 5;

int dist[maxn][maxn];
int timetag[maxn][maxn];
char G[maxn][maxn];
int n, m, k;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int sx, sy;

struct Node {
    int x, y, d;
    bool operator < ( const Node &oth ) const {
        return d > oth.d;
    }
};

void solve( )
{
    cin >> n >> m >> k;

    for( int i = 1; i <= k; ++ i )
    {
        int x, y;
        cin >> x >> y;
        if( i == 1 ) sx = x, sy = y, timetag[x][y] = 0;
        else timetag[x][y] = k - i + 1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        string s;
        cin >> s;
        for( int j = 1; j <= m; ++ j )
        {
            G[i][j] = s[j - 1];
            dist[i][j] = -1;
        }
    }

    priority_queue< Node > pq;
    dist[sx][sy] = 0;
    pq.push({ sx, sy, 0 });

    while( !pq.empty( ) )
    {
        auto [ x, y, d ] = pq.top( );
        pq.pop( );

        if( d > dist[x][y] ) continue;

        for( int dir = 0; dir < 4; ++ dir )
        {
            int nx = x + dx[dir], ny = y + dy[dir];
            if( nx < 1 || nx > n || ny < 1 || ny > m || G[nx][ny] == '#' ) continue;
            int nd = max( d + 1, timetag[nx][ny] );
            if( dist[nx][ny] == -1 || nd < dist[nx][ny] )
            {
                dist[nx][ny] = nd;
                pq.push({ nx, ny, nd });
            }
        }
    }

    ull ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            if( dist[i][j] != -1 ) ans += (ull)dist[i][j] * dist[i][j];
        }
    }
    cout << ans << '\n';
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