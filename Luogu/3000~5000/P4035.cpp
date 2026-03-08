#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 20 + 5;
const double eps = 1e-7;

double a[maxn][maxn];
double b[maxn];
double c[maxn][maxn];
int n;

int gauss( )
{
    int row = 1;
    for( int col = 1; col <= n; ++ col )
    {
        int pivot = row;
        for( int i = row + 1; i <= n; ++ i )
            if( fabs( c[i][col] ) > fabs( c[pivot][col] ) ) pivot = i;
        
        if( fabs( c[pivot][col] ) < eps ) continue;

        swap( c[pivot], c[col] );

        double div = c[row][col];
        for( int j = col; j <= n + 1; ++ j ) c[row][j] /= div;
        
        for( int i = 1; i <= n; ++ i )
        {
            if( i != row )
            {
                double fac = c[i][col];
                for( int j = col; j <= n + 1; ++ j )
                    c[i][j] -=  c[row][j] * fac;
            }
        }
        row ++;
    }

    if( row <= n )
    {
        for( int i = row; i <= n; ++ i )
            if( fabs( a[i][n + 1] ) > eps ) return -1;
        return 0;
    }
    return 1;
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    cin >> n;
    for( int i = 1; i <= n + 1; ++ i )
        for( int j = 1; j <= n; ++ j )
            cin >> a[i][j];

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            c[i][j] = 2 * ( a[i][j] - a[i+1][j] );
            c[i][n+1] += a[i][j] * a[i][j] - a[i+1][j] * a[i+1][j];
        }
    }

    gauss( );

    for( int i = 1; i <= n; ++ i )
        cout << fixed << setprecision( 3 ) << c[i][n+1] << ' ';

    return 0;
}