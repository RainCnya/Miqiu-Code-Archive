#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 2e18;

struct Node {
    ll pp, qq;
    ll xx, yy;
} pre[35][3][3];
ll dp[35][3][3];

ll x, y, p, q;
ll ans;

void DP( int optx, int opty )
{
    for( int i = 0; i <= 31; ++ i )
    for( int j = 0; j < 3; ++ j )
    for( int k = 0; k < 3; ++ k )
    dp[i][j][k] = inf;

    dp[0][1][1] = 0;

    for( int i = 0; i <= 30; ++ i )
    {
        ll cur = 1ll << i;
        int xb = (x >> i) & 1;
        int yb = (y >> i) & 1;

        for( int xx = 0; xx <= 2; ++ xx )
        {
            for( int yy = 0; yy <= 2; ++ yy )
            {
                if( dp[i][xx][yy] == inf ) continue;

                for( int pp = 0; pp <= 1; ++ pp )
                {
                    for( int qq = 0; qq <= 1; ++ qq )
                    {
                        if( pp == 1 && qq == 1 ) break;

                        int vx = xx - 1, vy = yy - 1;

                        if( optx == 1 ) vx += pp - xb;
                        else vx -= pp - xb;

                        if( opty == 1 ) vy += qq - yb;
                        else vy -= qq - yb;

                        int nx = (vx >> 1) + 1;
                        int ny = (vy >> 1) + 1;

                        if( nx < 0 || nx > 2 || ny < 0 || ny > 2 ) continue;

                        ll cost = ( ( vx & 1 ) + ( vy & 1 ) ) * cur;
                        if( dp[i][xx][yy] + cost < dp[i+1][nx][ny] )
                        {
                            dp[i+1][nx][ny] = dp[i][xx][yy] + cost;
                            pre[i+1][nx][ny] = { pp, qq, xx, yy };
                        }

                    }
                }

            }
        }

    }

    if( dp[31][1][1] < ans )
    {
        ans = dp[31][1][1];
        ll _p = 0, _q = 0;
        int xx = 1, yy = 1;

        for( int i = 31; i >= 1; -- i )
        {
            Node cur = pre[i][xx][yy];
            if( cur.pp ) _p |= ( 1ll << ( i - 1 ) );
            if( cur.qq ) _q |= ( 1ll << ( i - 1 ) );
            xx = cur.xx, yy = cur.yy;
        }
        p = _p, q = _q;
    }
}

void solve( )
{
    ans = inf;
    cin >> x >> y;

    DP( 1, 1 ); DP( 1, -1 );
    DP( -1, 1 ); DP( -1, -1 );

    cout << p << ' ' << q << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}