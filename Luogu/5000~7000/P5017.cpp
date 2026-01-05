#include<bits/stdc++.h>
using namespace std;

const int maxt = 4e6 + 50;
const int inf = 1e9;

int cnt[maxt];
long long sum[maxt];
int dp[maxt];
int n, m, mt;

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        cnt[x] += 1;
        sum[x] += x;
        mt = max( mt, x );
    }

    for( int i = 1; i <= mt + m; ++ i )
    {
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }

    for( int i = 1; i <= mt + m; ++ i )
    {
        dp[i] = inf;
    }
    dp[0] = 0;

    for( int i = 1; i <= mt + m; ++ i )
    {
        if( i < m )
        {
            dp[i] = i * cnt[i] - sum[i];
            continue;
        }
        for( int j = max(0, i - 2 * m); j <= i - m; ++ j )
        {
            int cost = i * ( cnt[i] - cnt[j] ) - (sum[i] - sum[j]);

            if( dp[j] != inf )
               dp[i] = min( dp[i], dp[j] + cost );
        }
    }

    int ans = inf;
    for( int i = mt; i < mt + m; ++ i )
    {
        ans = min( ans, dp[i] );
    }

    cout << ans << '\n';
    return 0;
}