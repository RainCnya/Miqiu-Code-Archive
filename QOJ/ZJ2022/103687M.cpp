#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1000 + 5;

bool vis[maxn][maxn];
string s[maxn];
int n, m;
int holes = 0;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool check( int x, int y )
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs( int x, int y )
{
    queue< PII > q;
    q.push({ x, y });
    vis[x][y] = 1;
    bool edge = 0;
    int cnt = 0;
    int x1 = x, x2 = x;
    int y1 = y, y2 = y;

    while( !q.empty( ) )
    {
        cnt ++;
        auto [x, y] = q.front( );
        q.pop( );

        if( x == 1 || x == n || y == 1 || y == m ) edge = 1;

        x1 = min( x1, x );
        x2 = max( x2, x );
        y1 = min( y1, y );
        y2 = max( y2, y );
        
        for( int dir = 0; dir < 4; ++ dir )
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if( check( nx, ny ) && s[nx][ny] == '.' && !vis[nx][ny] ) 
            {
                q.push({ nx, ny });
                vis[nx][ny] = 1;
            }
        }
    }
    
    if( edge || cnt != 12 ) return ;
    if( x2 - x1 + 1 != 4 || y2 - y1 + 1 != 4 ) return ;

    int row[4] = { 2, 4, 4, 2 };
    for( int i = 0; i < 4; ++ i )
    {
        for( int j = 0; j < 4; ++ j )
        {
            if( s[x1 + i][y1 + j] == '.' ) row[i] --;
        }
    }
    for( int i = 0; i < 4; ++ i )
    {
        if( row[i] != 0 ) return ;
    }
    holes ++;
}

void solve( )
{
    cin >> n >> m;

    int black = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
        for( int j = 1; j <= m; ++ j )
        {
            if( s[i][j] == '#' ) black ++;
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            if( s[i][j] == '.' && !vis[i][j] )
            {
                bfs( i, j );
            }
        }
    }

    for( int c = 0; c <= holes / 2; ++ c )
    {
        int s = holes - c * 2;
        if( 146 * c + 100 * s == black )
        {
            cout << c << ' ' << s << '\n';
            return;
        }
    }
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