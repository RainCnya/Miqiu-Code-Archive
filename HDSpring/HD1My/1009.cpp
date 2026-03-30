#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair< ll, ll >;

const int maxn = 1000 + 5;
const int bound = 200;

struct Node { ll x, y, cnt; };
struct F { ll x, y; } f[maxn];
int k;
int dist[bound << 1][bound << 1];

void solve( )
{
    cin >> k;
    memset( dist, -1, sizeof dist );
    
    bool zero = 0;
    for( int i = 1; i <= k; ++ i )
    {
        cin >> f[i].x >> f[i].y;
        if( f[i].x == 0 && f[i].y == 0 ) zero = 1;
    }
    if( zero ) { cout << 1 << '\n'; return; }
    
    queue< Node > q;

    for( int i = 1; i <= k; ++ i ) 
    {
        if( dist[f[i].x + bound][f[i].y + bound] == -1 )
            q.push( { f[i].x, f[i].y, 1LL } );
        dist[f[i].x + bound][f[i].y + bound] = 1;
    }

    while( !q.empty( ) )
    {
        auto [cx, cy, cnt] = q.front( ); q.pop( );

        if( cnt > 200 ) break;

        for( int i = 1; i <= k; ++ i )
        {
            ll nx = cx + f[i].x, ny = cy + f[i].y;
            if( abs( nx ) > bound || abs( ny ) > bound ) continue;
            if( nx == 0 && ny == 0 ) {
                cout << cnt + 1 << '\n';
                return;
            }
            if( dist[nx + bound][ny + bound] == -1 )
            {
                q.push( { nx, ny, cnt + 1LL } );
                dist[nx + bound][ny + bound] = cnt + 1;
            }
        }
    }
    cout << -1 << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}