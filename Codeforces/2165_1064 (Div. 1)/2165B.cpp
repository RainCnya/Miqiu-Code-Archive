#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 5e3 + 50;

long long dp[maxn];
int cnt[maxn];
int n;

void solve( )
{
    cin >> n;
    
    for( int i = 0; i <= n; ++ i )
    {
        cnt[i] = 0;
        dp[i] = 0;
    }
    
    int mx = 0;
    dp[0] = 1;
    
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        cnt[x] ++;
        mx = max( mx, cnt[x] );
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !cnt[i] ) continue;
        int w = cnt[i];
        int v = cnt[i];

        for( int j = n; j >= w; -- j )
        {
            dp[j] = ( dp[j] + ( dp[j - w] * v ) % mod ) % mod; 
        }
    }

    long long ans = 0;
    for( int j = mx; j <= n; ++ j )
    {
        ans = ( ans + dp[j] ) % mod;
    }
    
    cout << ans << '\n';
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while( t -- )
    {
        solve( );
    }    
    return 0;
}