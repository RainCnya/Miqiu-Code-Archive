#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

struct Point { ll x, y; } ans[maxn];

map< int, set< int > > hh, ww;
ll h[maxn], w[maxn];
ll H, W;
int n;

void solve( )
{
    cin >> H >> W >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> h[i] >> w[i];
        hh[ h[i] ].insert( i );
        ww[ w[i] ].insert( i );
    }

    ll cx = 1, cy = 1;
    ll ch = H, cw = W;

    for( int i = 1; i <= n; ++ i )
    {
        int idx = -1;
        if( hh.count( ch ) && !hh[ch].empty( ) )
        {
            idx = *hh[ch].begin( );
            ans[idx] = { cx, cy };
            cy += w[idx];
            cw -= w[idx];
        }
        else if( ww.count( cw ) && !ww[cw].empty( ) )
        {
            idx = *ww[cw].begin( );
            ans[idx] = { cx, cy };
            cx += h[idx];
            ch -= h[idx];
        }
        if( idx != - 1 )
        {
            hh[h[idx]].erase( idx );
            ww[w[idx]].erase( idx );
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << ans[i].x << " " << ans[i].y << "\n";
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}