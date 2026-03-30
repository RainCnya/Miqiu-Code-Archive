#include <bits/stdc++.h>
using namespace std;

const int maxn = 20 + 5;

int n, m, t;
char maze[maxn][maxn];
bool vis[maxn][maxn];
bool found;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check( int x, int y )
{
    return 1 <= x && x <= m && 1 <= y && y <= n;
}

void dfs( int x, int y, int step ) 
{
    // cout << x << ' ' << y << ' ' << step << '\n';
    if( found || step > t ) return ;

    if( maze[x][y] == 'P' ) { found = true; return; }

    for( int d = 0; d < 4; ++ d )
    {
        int nx = x + dx[d], ny = y + dy[d];

        if( check( nx, ny ) && !vis[nx][ny] && maze[nx][ny] != '*' )
        {
            vis[nx][ny] = 1;
            dfs(nx, ny, step + 1);
            vis[nx][ny] = 0;
        }
    }
}

void solve( )
{
    if( !n && !m && !t ) return;

    int stx = 1, sty = 1;
    found = false;
    
    for( int i = 1; i <= m; ++ i ) 
    {
        for( int j = 1; j <= n; ++ j ) 
        {
            vis[i][j] = 0;
            cin >> maze[i][j];
            if( maze[i][j] == 'S' ) stx = i, sty = j;
        }
    }

    vis[stx][sty] = true;
    dfs( stx, sty, 0 );

    if( found ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while( cin >> n >> m >> t ) solve( );
    return 0;
}