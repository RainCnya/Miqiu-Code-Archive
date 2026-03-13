#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxsz = 100 + 5;

ll n, mod, p, q, a1, a2;

struct Matrix {
    ll m[maxsz][maxsz];
    int sz;
    Matrix( int s = 0 ) : sz( s ) { memset( m, 0, sizeof( m ) ); }
    void init( ) { for( int i = 1; i <= sz; ++ i ) m[i][i] = 1; }

    friend Matrix operator * ( const Matrix &a, const Matrix &b ) {
        Matrix res( a.sz );
        for( int i = 1; i <= res.sz; ++ i ) {
            for( int k = 1; k <= res.sz; ++ k ) {
                if( a.m[i][k] == 0 ) continue;
                for( int j = 1; j <= res.sz; ++ j )
                    res.m[i][j] = ( res.m[i][j] + a.m[i][k] * b.m[k][j] ) % mod;
            }
        }
        return res;
    }
};

Matrix mqpow( Matrix a, ll k ) 
{
    Matrix res( a.sz ); res.init( );
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
    
    Matrix T( 2 );
    T.m[1][1] = p, T.m[1][2] = q, T.m[2][1] = 1;
    T = mqpow( T, n - 2 );

    cout << ( T.m[1][1] * a2 + T.m[1][2] * a1 ) % mod << '\n';
    return 0;
}