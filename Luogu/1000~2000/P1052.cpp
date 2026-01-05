#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 1e5 + 50;

int dp[maxn];
int a[maxn];
bool flag[maxn];
int l, s, t, m;

int main() {
    cin >> l >> s >> t >> m;

    for( int i = 1; i <= m; ++ i )
        cin >> a[i];

        if( s == t )
    {
        int ans = 0;
        for( int i = 1; i <= m; ++ i )
            if( a[i] % s == 0 ) ans ++;
        cout << ans << '\n';
        return 0;
    }

    sort( a+1, a+m+1 );
    a[0] = 0,   a[m+1] = l;
    int len = 0;

    int safe = 100;

    for( int i = 1; i <= m + 1; ++ i )
    {
        int diff = a[i] - a[i-1];
        len += min( diff, safe );
        if( i <= m ) flag[len] = 1;
    }

    memset( dp, 0x3f, sizeof( dp ) );

    dp[0] = 0;
    for( int i = 1; i <= len + t; ++ i )
    {
        for( int j = s; j <= t; ++ j )
        {
            if( (i - j) >= 0 )
                dp[i] = min( dp[i], dp[i-j] + flag[i] );
        }
    }

    int ans = inf;
    for( int i = len; i <= len + t; ++ i )
    {
        ans = min( ans, dp[i] );
    }

    cout << ans << '\n';
    return 0;
}