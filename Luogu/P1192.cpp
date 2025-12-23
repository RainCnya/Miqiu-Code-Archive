#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;
const int mod = 100003;

int n, k;
int dp[maxn];

int main()
{	
    cin >> n >> k;
    dp[0] = dp[1] = 1;
    for( int i = 2; i <= n; ++ i )
    {
        for( int j = 1; j <= k; ++ j )
        {
            if( i - j < 0 ) break;
            dp[i] = ( dp[i] + dp[i-j] ) % mod;
        }
    }
    cout << dp[n] % mod << '\n';
    return 0;
}

/*
    1

*/