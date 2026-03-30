#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

double c[maxn][maxn];
int n, m;
int a[maxn];

void solve( )
{
    for( int i = 1; i < n; ++ i ) cin >> a[i];

    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= n; ++ j )
            c[i][j] = 0.0;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v; double cost;
        cin >> u >> v >> cost;
        c[u][v] = c[v][u] = (1.0 - cost);
    }

    for( int k = 1; k <= n; ++ k )
    {
        for( int i = 1; i <= n; ++ i )
        {
            for( int j = 1; j <= n; ++ j )
            {
                if( c[i][k] == 0.0 || c[k][j] == 0.0 ) continue;
                c[i][j] = max( c[i][j], c[i][k] * c[k][j] );
            }
        }
    }
    
    // for( int i = 1; i <= n; ++ i )
    // {
    //     for( int j = 1; j <= n; ++ j )
    //     {
    //         cout << c[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    double ans = 0;
    for( int i = 1; i < n; ++ i )
    {
        ans += a[i] * c[i][n];
    }
    cout << fixed << setprecision(2) << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while( cin >> n >> m ) solve( );
    return 0;
}