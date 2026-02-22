#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

int memo[maxn][maxn];
int g[maxn][maxn];
int r, c, ans;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool check( int x, int y ) { return 1 <= x && x <= r && 1 <= y && y <= c; }

int dfs( int x, int y )
{
    if( !check( x, y ) ) return 0;
    if( memo[x][y] != -1 ) return memo[x][y];

    int res = 0;
    for( int dir = 0; dir < 4; ++ dir )
    {
        int nx = x + dx[dir], ny = y + dy[dir];
        if( check( nx, ny ) && g[x][y] > g[nx][ny] ) res = max( res, dfs( nx, ny ) );
    }
    return memo[x][y] = res + 1;
}

void solve( )
{
    cin >> r >> c;
    for( int i = 1; i <= r; ++ i )
        for( int j = 1; j <= c; ++ j )
            cin >> g[i][j];

    memset( memo, -1, sizeof(memo) );
    for( int i = 1; i <= r; ++ i )
    {
        for( int j = 1; j <= c; ++ j )
        {
            ans = max( ans, dfs( i, j ) );
        }
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