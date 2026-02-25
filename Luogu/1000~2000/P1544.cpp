#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const ll inf = 1e18;

ll f[maxn][maxn][maxn];
// f[i][j][k] -> 走到 (i, j) 用了 k 次 *3 的 最大得分
ll a[maxn][maxn];
int n, kk;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> kk;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= i; ++ j )
        {
            cin >> a[i][j];
        }
    }

    for( int j = 1; j <= n; ++ j )
    {
        f[n][j][0] = a[n][j], f[n][j][1] = a[n][j] * 3;
        for( int k = 2; k <= kk; ++ k ) f[n][j][k] = -inf;
    }

    for( int i = n - 1; i >= 1; -- i )
    {
        for( int j = 1; j <= i; ++ j )
        {
            for( int k = 0; k <= kk; ++ k )
            {
                f[i][j][k] = max( f[i+1][j][k], f[i+1][j+1][k] ) + a[i][j];
                if( k >= 1 ) f[i][j][k] = max( f[i][j][k], 
                    max( f[i+1][j][k-1], f[i+1][j+1][k-1] ) + a[i][j] * 3 );
            }
        }
    }

    ll ans = -inf;
    for( int k = 0; k <= kk; ++ k ) ans = max( ans, f[1][1][k] );
    cout << ans << '\n';
    return 0;
}