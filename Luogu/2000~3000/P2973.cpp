#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 5;
const double eps = 1e-7;

double a[maxn][maxn];
int g[maxn][maxn];
int deg[maxn];
int n, m, p, q;
double P;

void gauss( )
{
    int row = 1;
    for( int col = 1; col <= n; ++ col )
    {
        int pivot = row;
        for( int i = row + 1; i <= n; ++ i )
            if( fabs( a[i][col] ) > fabs( a[pivot][col] ) ) pivot = i;
        
        if( fabs( a[pivot][col] ) < eps ) continue;

        swap( a[pivot], a[col] );

        double div = a[row][col];
        for( int j = col; j <= n + 1; ++ j ) a[row][j] /= div;
        
        for( int i = 1; i <= n; ++ i )
        {
            if( i != row )
            {
                double fac = a[i][col];
                for( int j = col; j <= n + 1; ++ j )
                    a[i][j] -= fac * a[row][j];
            }
        }
        row ++;
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    cin >> n >> m >> p >> q;
    P = 1.0 * p / q;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v; cin >> u >> v;
        if( g[u][v] ) continue;
        g[u][v] = g[v][u] = 1;
        deg[u] ++, deg[v] ++;
    }

    for( int i = 1; i <= n; ++ i )
    {
        a[i][i] = 1;
        for( int j = 1; j <= n; ++ j )
        {
            if( g[i][j] ) a[i][j] -= ( 1.0 - P ) / deg[j];
        }
    }
    a[1][n + 1] = 1.0;
    gauss( );

    cout << fixed << setprecision( 9 );

    for( int i = 1; i <= n; ++ i )
    {
        double ans = a[i][n + 1] * P;
        cout << ans << '\n';
    }

    return 0;
}