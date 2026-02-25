#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 1e3 + 5;
const int maxm = 200 + 5;
const int mod = 1e9 + 7;

// f[k][i][j] 表示取 k 段且 A[i] 必须选，匹配 B[j]
int f[2][maxn][maxm];
// g[k][i][j] 表示取 k 段且 A[i] 可选，匹配 B[j]
int g[2][maxn][maxm];
int n, m, kk;
string A, B;

int main( )
{
    cin >> n >> m >> kk;
    cin >> A >> B;
    A = ' ' + A, B = ' ' + B;

    for( int i = 0; i <= n; ++ i )  g[0][i][0] = 1;

    int cur = 1;
    for( int k = 1; k <= kk; ++ k )
    {
        memset( f[cur], 0, sizeof( f[cur] ) );
        memset( g[cur], 0, sizeof( g[cur] ) );

        for( int i = 1; i <= n; ++ i )
        {
            for( int j = 1; j <= m; ++ j )
            {
                if( A[i] == B[j] ) f[cur][i][j] = ( f[cur][i-1][j-1] + g[cur^1][i-1][j-1] ) % mod;
                else f[cur][i][j] = 0;
                g[cur][i][j] = ( f[cur][i][j] + g[cur][i-1][j] ) % mod;
            }
        }
        cur ^= 1;
    }

    cout << g[cur^1][n][m] << '\n';
    return 0;
}