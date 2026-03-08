#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxsz = 100 + 5;
const int maxn = 100 + 5;
const int mod = 2009;

int n, t;

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

char c;

int getid( int i, int j ) { return i + j * n; }

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );

    cin >> n >> t;
    int sz = n * 9;
    Matrix A( sz );

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= 8; ++ j )
            A.m[getid( i, j )][getid( i, j - 1 )] = 1;
        
        for( int j = 1; j <= n; ++ j )
        {
            cin >> c;
            if( c == '0' ) continue;
            int w = c - '0';
            A.m[getid( i, 0 )][getid( j, w - 1 )] = 1;
        }
    }

    Matrix res = mqpow( A, t );
    cout << res.m[getid( 1, 0 )][getid( n, 0 )] << '\n';
    return 0;
}