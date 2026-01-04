#include <bits/stdc++.h>
using namespace std;

const int max_mask = ( 1 << 20 ) + 5;
int memo[max_mask];

int calc_SG( int mask )
{
    if( memo[mask] != -1 ) return memo[mask];

    bool vis[25];
    memset( vis, 0, sizeof( vis ) );

    for( int i = 19; i >= 0; -- i )
    {
        if( ( mask >> i ) & 1 )
        {
            int nxt = -1;
            for( int j = i - 1; j >= 0; -- j )
            {
                if( ( mask >> j ) & 1 ) continue;
                nxt = j;
                break;
            }
            if( nxt != -1 )
            {
                int nxt_mask = mask;
                nxt_mask ^= ( 1 << i );
                nxt_mask |= ( 1 << nxt );
                int nxt_SG = calc_SG( nxt_mask );
                if( nxt_SG < 25 ) vis[nxt_SG] = 1;
            }
        }
    }

    int res = 0;
    while( vis[res] ) res ++;
    return memo[mask] = res;
}

void solve( )
{
    int n, m;
    int xor_sum = 0;

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> m;
        int mask = 0;

        for( int j = 1; j <= m; ++ j )
        {
            int pos;
            cin >> pos;
            mask |= ( 1 << ( 20 - pos ) );
        }
        xor_sum ^= calc_SG( mask );
    }

    if( xor_sum == 0 ) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    memset( memo, -1, sizeof( memo ) );
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
