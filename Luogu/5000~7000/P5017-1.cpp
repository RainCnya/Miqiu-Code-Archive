#include<bits/stdc++.h>
using namespace std;

const int maxn = 505;
const int maxt = 100505; 
const int inf = 1e9;

long long sum[maxt]; 
int dp[maxt];
int cnt[maxt]; 
int a[maxn];
int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    for( int i = 1; i <= n; ++ i )
        cin >> a[i];
    
    sort( a + 1, a + 1 + n );

    int offset = 0;
    if( a[1] > 2 * m ) 
    {
        offset = a[1] - 2 * m;
        a[1] = 2 * m;
    }
    
    for( int i = 2; i <= n; ++ i ) 
    {
        a[i] -= offset;
        int diff = a[i] - a[i-1];
        if (diff > 2 * m) 
        {
            int tmp = diff - 2 * m;
            offset += tmp;
            a[i] -= tmp;
        }
    }
    
    int end = a[n];

    for( int i = 1; i <= n; ++ i ) 
    {
        cnt[ a[i] ] += 1;
        sum[ a[i] ] += a[i];
    }

    for( int i = 1; i <= end + m; ++ i ) 
    {
        cnt[i] += cnt[i-1];
        sum[i] += sum[i-1];
    }

    for( int i = 0; i <= end + m; ++ i ) 
        dp[i] = inf;
    dp[0] = 0;

    for(int i = 1; i <= end + m; ++ i ) 
    {
        if( i >= m && cnt[i] == cnt[i-m] ) 
        {
             dp[i] = dp[i-m]; 
             continue;
        }

        if( i < m ) 
        {
            dp[i] = i * cnt[i] - sum[i];
            continue;
        }
        
        for( int j = max(0, i - 2 * m); j <= i - m; ++ j ) {
            int cost = i * (cnt[i] - cnt[j]) - (sum[i] - sum[j]);
            if( dp[j] != inf )
               dp[i] = min( dp[i], dp[j] + cost );
        }
    }

    int ans = inf;
    for(int i = end; i < end + m; ++i) {
        ans = min( ans, dp[i] );
    }

    cout << ans << '\n';
    return 0;
}