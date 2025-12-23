#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

int n, k;
int dp[maxn];

int main()
{	
    cin >> n >> k;
    // int k = n - 1;
    
    dp[0] = dp[1] = 1;
    for( int i = 2; i <= n; ++ i )
    {
        if( i <= k ) 
            dp[i] = ( 2 * dp[i-1] ) % mod;
        else
            dp[i] = ( (2 * dp[i-1]) % mod - (dp[i-k-1] % mod) + mod) % mod ;
    }
    
    cout << dp[n] << '\n';
    return 0;
}