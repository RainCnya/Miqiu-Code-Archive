#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e4 + 50;

ll dp[maxn][2];
// dp[i][0] 表示走完第i行停在左端点
// dp[i][1] 表示走完第i行停在右端点
int l[maxn], r[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> l[i] >> r[i];
    }

    dp[1][0] = r[1] - 1 + ( r[1] - l[1] );
    dp[1][1] = r[1] - 1;

    for( int i = 2; i <= n; ++ i )
    {
        int len = r[i] - l[i] + 1;
        dp[i][0] = min( dp[i-1][0] + abs( l[i-1] - r[i] ) + len, 
                        dp[i-1][1] + abs( r[i-1] - r[i] ) + len );
        
        dp[i][1] = min( dp[i-1][0] + abs( l[i-1] - l[i] ) + len, 
                        dp[i-1][1] + abs( r[i-1] - l[i] ) + len );
    }

    cout << min( dp[n][0] + n - l[n], dp[n][1] + n - r[n] ) << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}