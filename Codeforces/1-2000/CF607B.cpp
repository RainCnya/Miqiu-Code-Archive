#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 500 + 5;

int f[maxn][maxn];
// f[i][j] 表示 a[i...j] 消除次数
int a[maxn];
int n;

int main( )
{
    cin >> n;

    memset( f, 0x3f, sizeof( f ) );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        f[i][i] = 0;
    }

    for( int len = 0; len <= n; ++ len )
    {
        for( int i = 1; i + len - 1 <= n; ++ i )
        {
            int j = i + len - 1;

            if( a[i] == a[j] )
            {
                if( len < 2 ) f[i][j] = 1;
                else f[i][j] = min( f[i][j], f[i+1][j-1] );
            }

            for( int k = i; k < j; ++ k )
            {
                f[i][j] = min( f[i][j], f[i][k] + f[k+1][j] );
            }
        }
    }

    cout << f[1][n] << '\n';
    return 0;
}