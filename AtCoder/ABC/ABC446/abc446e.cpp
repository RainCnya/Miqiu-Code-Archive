#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

ll m, a, b;
int memo[maxn][maxn];
bool vis[maxn][maxn];

int dfs( int x, int y )
{
    if( x == 0 || y == 0 ) return 0;
    if( memo[x][y] != -1 ) return memo[x][y];
    if( vis[x][y] ) return 1;


    vis[x][y] = 1;
    ll nxt = ( a * y + b * x ) % m;
    int res = dfs( y, nxt );
    vis[x][y] = 0;

    return memo[x][y] = res;
}

void solve( )
{
    cin >> m >> a >> b;

    memset( memo, -1, sizeof( memo ) );

    ll cnt = 0;
    for( int x = 0; x <= m - 1; ++ x )
        for( int y = 0; y <= m - 1; ++ y )
            cnt += ( dfs( x, y ) == 1 );

    cout << cnt << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}