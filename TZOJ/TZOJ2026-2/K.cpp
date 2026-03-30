#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

double a[maxn], b[maxn];
double dp[maxn][3];
double w[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> w[i];
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    double ans =-1e18;
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for( int i = 1; i <= n; ++ i )
    {
        dp[i][2] = dp[i - 1][2] * a[i];
        dp[i][1] = max( dp[i-1][1] * a[i], dp[i-1][2] * b[i] );
        dp[i][0] = max( dp[i-1][0] * a[i], max( dp[i-1][1] * b[i], dp[i-1][1] * b[i] ) );
        ans = max( ans, dp[i][0] * w[i] );
        ans = max( ans, dp[i][1] * w[i] );
        ans = max( ans, dp[i][2] * w[i] );
    }
    cout << fixed << setprecision( 6 ) << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}