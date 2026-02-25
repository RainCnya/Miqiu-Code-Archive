#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 5;

int f[maxn][maxn];
// f[i][j] 表示 a[i...j] 合并的最小代价
int a[maxn], sum[maxn];
int n;

int main( )
{
    cin >> n;

    memset( f, 0x3f, sizeof( f ) );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        f[i][i] = 0;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int i = 1; i + len - 1 <= n; ++ i )
        {
            int j = i + len - 1;
            for( int k = i; k < j; ++ k )
            {
                f[i][j] = min( f[i][j], f[i][k] + f[k+1][j] + sum[j] - sum[i-1] );
            }
        }
    }

    cout << f[1][n] << '\n';
    return 0;
}