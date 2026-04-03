#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 5;

struct Point { int x, y, d; };

vector< int > adj[maxn];
int match[maxn];
bool vis[maxn];
int n;

bool dfs( int u )
{
    for( int v : adj[u] )
    {
        if( vis[v] ) continue;
        vis[v] = true;
        if( match[v] == -1 || dfs( match[v] ) )
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve( )
{
    cin >> n;
    map< int, int > mp[4];
    for( int i = 1; i <= n; ++ i )
    {
        int x, y, d; cin >> x >> y >> d;
        
        if( d == 0 ) { // 向上 ymax
            if( mp[d].find( x ) == mp[d].end( ) || y > mp[d][x] ) mp[d][x] = y;
        }
        else if( d == 1 ) { // 向右 xmax
            if( mp[d].find( y ) == mp[d].end( ) || x > mp[d][y] ) mp[d][y] = x;
        }
        else if( d == 2 ) { // 向下 ymin
            if( mp[d].find( x ) == mp[d].end( ) || y < mp[d][x] ) mp[d][x] = y;
        }
        else if( d == 3 ) { // 向左 xmin
            if( mp[d].find( y ) == mp[d].end( ) || x < mp[d][y] ) mp[d][y] = x;
        }
    }

    vector< Point > ps1, ps2;
    for( int d = 0; d < 4; ++ d )
    {
        // 水平方向 mp[d][y] = x
        if( d == 1 || d == 3 ) for( auto [y, x] : mp[d] ) {
            ps1.push_back({ x, y, d });
        }
        // 垂直方向 mp[d][x] = y
        else for( auto [x, y] : mp[d] ) {
            ps2.push_back({ x, y, d });
        }
    }

    int sz1 = ps1.size( ), sz2 = ps2.size( );
    for( int i = 0; i < sz1; ++ i ) adj[i].clear( );

    for( int i = 0; i < sz1; ++ i )
    {
        for( int j = 0; j < sz2; ++ j )
        {
            bool ok1 = 0, ok2 = 0;

            if( ps1[i].d == 1 ) { // 向右
                if( ps2[j].x >= ps1[i].x ) ok1 = 1;
            } else { // 向左
                if( ps2[j].x <= ps1[i].x ) ok1 = 1;
            }

            if( ps2[j].d == 0 ) { // 向上
                if( ps1[i].y >= ps2[j].y ) ok2 = 1;
            } else { // 向下
                if( ps1[i].y <= ps2[j].y ) ok2 = 1;
            }

            if( ok1 && ok2 ) adj[i].push_back( j );
        }
    }

    int ans = 0;
    memset( match, -1, sizeof( match ) );
    for( int i = 0; i < sz1; ++ i )
    {
        memset( vis, 0, sizeof( vis ) );
        if( dfs( i ) ) ++ ans;
    }
    cout << ( sz1 + sz2 - ans ) << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}