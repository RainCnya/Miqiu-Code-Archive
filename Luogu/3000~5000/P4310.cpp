#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int n, ans;
int a[maxn];
int dp[maxn];

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i <= n; ++ i )
    {
        int now = 1;
        for( int j = 0; j <= 30; ++ j )
        {
            if( (a[i] >> j) & 1 ) {
                now = max( now, dp[j] + 1 );
            }
        }
        for( int j = 0; j <= 30; ++ j )
        {
            if( (a[i] >> j) & 1 ) {
                dp[j] = max( dp[j], now );
            }
        }
        ans = max( ans, now );
    }

    cout << ans << '\n';
    return 0;
}