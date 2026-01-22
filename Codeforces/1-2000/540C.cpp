#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 5;

bool flag = 0;
bool vis[N][N];
char cave[N][N];
int r1, c1, r2, c2;
int n, m;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool check( int x, int y )
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int calc( )
{
    int cnt = 0;
    for( int d = 0; d < 4; ++ d )
    {
        int nx = r2 + dx[d], ny = c2 + dy[d];
        if( check( nx, ny) && cave[nx][ny] == '.' )
            cnt ++;
    }
    return cnt;
}

bool bfs( )
{
    queue<pair<int, int>> q;
    memset( vis, 0, sizeof( vis ) );
    q.push( {r1, c1} );
    vis[r1][c1] = 1;

    while( !q.empty( ) )
    {
        auto [x, y] = q.front( ); q.pop( );
        if( x == r2 && y == c2 )
            return true;
        for( int d = 0; d < 4; ++ d )
        {
            int nx = x + dx[d], ny = y + dy[d];
            if( !check( nx, ny ) || vis[nx][ny] ) continue;
            if( cave[nx][ny] == '.' || (nx == r2 && ny == c2) )
            {
                vis[nx][ny] = true;
                q.push( {nx, ny} );
            }
        }
    }
    return false;
}

int main( )
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
            cin >> cave[i][j];
    }
    cin >> r1 >> c1 >> r2 >> c2;

    int cnt = calc( );
    int dist = abs( r1 - r2 ) + abs( c1 - c2 );
    if( dist == 0 )
    {
        if( cnt >= 1 )
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }
    if( dist == 1 )
    {
        if( cave[r2][c2] == 'X' )
            cout << "YES";
        else if( cnt >= 1 )
            cout << "YES";
        else
            cout << "NO";
        return 0;
    }
    

    flag = bfs( );
    if( !flag )
    {
        cout << "NO" << endl;
        return 0;
    }

    if( cave[r2][c2] == 'X' && cnt >= 1 )
    {
        cout << "YES";
        return 0;
    }
    else if( cave[r2][c2] == '.' && cnt >= 2 )
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}