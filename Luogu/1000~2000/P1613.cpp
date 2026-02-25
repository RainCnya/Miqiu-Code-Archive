#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 50 + 5;
const ll inf = 1e18;

bool f[maxn][maxn][maxn];
// f[k][u][v] 表示 存在一条 长度为 2^k，从 u 到 v 的路径
ll dist[maxn][maxn];
int n, m;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // input
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        f[0][u][v] = 1;
    }

    // DP 辅助建图
    for( int i = 1; i <= 30; ++ i )
        for( int k = 1; k <= n; ++ k )
            for( int u = 1; u <= n; ++ u )
                for( int v = 1; v <= n; ++ v )
                    f[i][u][v] |= ( f[i - 1][u][k] & f[i - 1][k][v] );

    // dist 初始化
    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= n; ++ j )
            if( i == j ) dist[i][j] = ( i == 1 ? 0 : inf );

    for( int i = 0; i <= 30; ++ i )
        for( int u = 1; u <= n; ++ u )
            for( int v = 1; v <= n; ++ v )
                if( f[i][u][v] ) dist[u][v] = min( dist[u][v], 1ll );

    // floyd
    for( int k = 1; k <= n; ++ k )
        for( int u = 1; u <= n; ++ u )
            for( int v = 1; v <= n; ++ v )
                dist[u][v] = min( dist[u][v], dist[u][k] + dist[k][v] );

    cout << dist[1][n] << '\n';
    return 0;
}