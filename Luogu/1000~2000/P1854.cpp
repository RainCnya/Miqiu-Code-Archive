#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

int n, m;
int a[maxn][maxn];
int f[maxn][maxn];
// f[i][j] 前 i 个花瓶，插了 j 朵花的最大值

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> a[i][j];
        }
    }

    memset( f, 128, sizeof( f ) );

    for( int j = 0; j <= m; ++ j ) f[0][j] = 0;

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = i; j <= m - ( n - i ); ++ j )
        {
            f[i][j] = f[i-1][j-1] + a[i][j];
            if( j > i && f[i][j-1] > f[i][j] ) f[i][j] = f[i][j-1];
        }
    }

    cout << f[n][m] << '\n';

    vector< int > ans;
    int cur = n;
    for( int j = m; j >= 1; -- j )
    {
        if( f[cur][j] == f[cur-1][j-1] + a[cur][j] )
        {
            ans.push_back( j );
            cur --;
        }
    }

    for( int i = n - 1; i >= 0; -- i ) cout << ans[i] << ' ';

    return 0;
}