#include <bits/stdc++.h>
using namespace std;

int vis[25];
int n, m;

void solve( )
{
    int xor_sum = 0;

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> m;
        memset( vis, 0, sizeof( vis ) );

        for( int j = 1; j <= m; ++ j )
        {
            int pos;
            cin >> pos;
            vis[pos] = 1;
        }

        int xor_row = 0;
        int cnt = 0;
        int cur = 20 - m + 1;

        for( int j = 1; j <= 20; ++ j )
        {
            if( vis[j] ) cnt ++;
            else
            {
                cur --;
                if( cur & 1 ) xor_sum ^= cnt;
                cnt = 0;
            }
        }

        xor_sum ^= xor_row;
    }

    if( xor_sum == 0 ) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
