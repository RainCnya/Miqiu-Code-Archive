#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 30 + 5;
const int maxv = 2e4 + 5;

int dp[maxn][maxv];
// dp[i][j] 表示前 i 个物品，容量为 j 最多装下的体积
int a[maxn];
int n, v;

void solve( )
{
    cin >> v;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= v; ++ j )
        {
            if( j >= a[i] ) dp[i][j] = max( dp[i-1][j], dp[i-1][j - a[i]] + a[i] );
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << v - dp[n][v] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}