#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const double eps = 1e-7;

double a[maxn][maxn];
int n;

// 1 唯一解 | 0 无穷解 | -1 无解
int gauss( )
{
    int curi = 1;
    for( int j = 1; j <= n; ++ j )
    {
        int p = curi;
        for( int i = curi + 1; i <= n; ++ i )
            if( fabs( a[i][j] ) > fabs( a[p][j] ) ) p = i;
        
        if( fabs( a[p][j] ) < eps ) continue;

        swap( a[p], a[curi] );

        double div = a[curi][j];
        for( int k = j; k <= n + 1; ++ k ) a[curi][k] /= div;
        
        for( int i = 1; i <= n; ++ i )
        {
            if( i != curi && fabs( a[i][j] ) > eps )
            {
                double mul = a[i][j];
                for( int k = j; k <= n + 1; ++ k )
                    a[i][k] -=  a[curi][k] * mul;
            }
        }
        curi ++;
    }

    if( curi <= n )
    {
        for( int i = curi; i <= n; ++ i )
            if( fabs( a[i][n + 1] ) > eps ) return -1;
        return 0;
    }
    return 1;
}


int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    cin >> n;

    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= n + 1; ++ j )
            cin >> a[i][j];

    int res = gauss( );
    
    if( res == 1 )
    {
        for( int i = 1; i <= n; ++ i )
            cout << "x" << i << "=" << fixed << setprecision( 2 ) << a[i][n + 1] << '\n';
    }
    else cout << res << '\n';
    return 0;
}