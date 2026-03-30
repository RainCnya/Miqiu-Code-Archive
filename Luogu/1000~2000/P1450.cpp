#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

ll dp[maxn];
ll d[5], c[5], s;
int n, Q;

ll get( int x ) { return x < 0 ? 0 : dp[x]; }

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> c[1] >> c[2] >> c[3] >> c[4] >> Q;

    dp[0] = 1;
    for( int i = 1; i <= 4; ++ i )
    {
        for( int j = c[i]; j <= maxn; ++ j )
        {
            dp[j] += dp[j - c[i]];
        }
    }

    while( Q -- )
    {
        for( int i = 1; i <= 4; ++ i )
        {
            cin >> d[i];
            d[i] = ( d[i] + 1 ) * c[i];
        }
        cin >> s;
        ll ans = dp[s];
        ans -= get( s - d[1] ) + get( s - d[2] ) + get( s - d[3] ) + get( s - d[4] );
        ans += get( s - d[1] - d[2] ) + get( s - d[1] - d[3] ) + get( s - d[1] - d[4] )
            + get( s - d[2] - d[3] ) + get( s - d[2] - d[4] ) + get( s - d[3] - d[4] );
        ans -= get( s - d[1] - d[2] - d[3] ) + get( s - d[1] - d[2] - d[4] )
            + get( s - d[1] - d[3] - d[4] ) + get( s - d[2] - d[3] - d[4] );
        ans += get( s - d[1] - d[2] - d[3] - d[4] );
        cout << ans << '\n';
    }

    return 0;
}