#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

ll n, mod, p, q, a1, a2;

int L = 3;
struct Matrix {
    ll m[maxn][maxn];
    void clear( ) { memset( m, 0, sizeof( m ) ); }
    void init( ) { clear( );
        for( int i = 1; i <= L; ++ i ) m[i][i] = 1; 
    }
    
    Matrix friend operator * ( const Matrix &a, const Matrix &b ) {
        Matrix res; res.clear( );
        for ( int i = 1; i <= L; i++ )
            for ( int j = 1; j <= L; j++ )
                for ( int k = 1; k <= L; k++ )
                    res.m[i][j] = ( res.m[i][j] + a.m[i][k] * b.m[k][j] ) % mod;
        return res;
    }
} A;

Matrix mqpow( Matrix a, ll k ) {
    Matrix res; res.init( );
    for( ; k; k >>= 1, a = a * a )
        if( k & 1 ) res = res * a;
    return res;
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    cin >> p >> q >> a1 >> a2 >> n >> mod;

    if( n == 1 ) { cout << a1 << '\n'; return 0; }
    if( n == 2 ) { cout << a2 << '\n'; return 0; }

    A.m[1][1] = p, A.m[1][2] = q, A.m[2][1] = 1;
    A = mqpow( A, n - 2 );

    cout << ( A.m[1][1] * a2 + A.m[1][2] * a1 ) % mod << '\n';
    return 0;
}