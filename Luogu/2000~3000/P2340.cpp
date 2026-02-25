#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 400 + 5;
const int offset = 4e5;
const int maxw = 8e5 + 5;
const int inf = 0x3f3f3f3f;

int dp[maxw];
int w, v;
int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    memset( dp, 128, sizeof( dp ) );
    dp[offset] = 0;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> w >> v;

        if( w >= 0 )
        {
            for( int j = maxw - 1; j >= w; -- j )
            {
                dp[j] = max( dp[j], dp[j - w] + v );
            }
        }
        else
        {
            for( int j = 0; j <= maxw - 1 + w; ++ j )
            {
                dp[j] = max( dp[j], dp[j - w] + v );
            }
        }
    }

    int ans = 0;
    for( int j = offset; j <= maxw - 1; ++ j )
    {
        if( dp[j] > 0 ) ans = max( ans, (j - offset) + dp[j] );
    }
    cout << ans << '\n';
    return 0;
}