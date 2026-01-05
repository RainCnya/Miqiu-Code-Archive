#include<bits/stdc++.h>
using namespace std;

const int maxn = 4200 + 50;

int n, p;
long long dp[2][maxn];

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;

    dp[0][2] = 1;

    for( int i = 3; i <= n; ++ i )
    {
        int cur = i & 1;
        int pre = ( i - 1 ) & 1;

        dp[cur][1] = 0;
        for( int j = 2; j <= i; ++ j )
        {
            dp[cur][j] = ( dp[cur][j-1] + dp[pre][i-j+1] ) % p;  
        }
    }

    long long ans = 0;
    for( int j = 2; j <= n; ++ j )
    {
        ans = ( ans + dp[n & 1][j] ) % p;
    }

    cout << ( ans << 1 ) % p << '\n';
    return 0;
}