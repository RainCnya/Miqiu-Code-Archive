#include<bits/stdc++.h>
using namespace std;

const int maxn = 105 * 2;

int dp[maxn][maxn];
int a[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= 2 * n; ++ l )
        {
            int r = l + len - 1;
            for( int k = l; k < r; ++ k )
            {   // [l, k] -- [k+1, r]
                int cur = a[l] * a[k + 1] * a[r + 1];
                dp[l][r] = max( dp[l][r], dp[l][k] + dp[k+1][r] + cur );
            }
        }
    }

    int ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans = max( ans, dp[i][i + n - 1 ] );
    }
    
    cout << ans << '\n';
    return 0;
}