#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const int mod = 1e9 + 7;

ll n;

int L = 4;
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
};

Matrix mqpow( Matrix a, ll k ) {
    Matrix res; res.init( );
    for( ; k; k >>= 1, a = a * a )
        if( k & 1 ) res = res * a;
    return res;
}

void solve( )
{
    cin >> n;
    if( n <= 3 ) { cout << 1 << '\n'; return; }

    Matrix A;

    A.m[1][1] = 1, A.m[1][2] = 0, A.m[1][3] = 1;
    A.m[2][1] = 1, A.m[2][2] = 0, A.m[2][3] = 0;
    A.m[3][1] = 0, A.m[3][2] = 1, A.m[3][3] = 0;

    A = mqpow( A, n - 3 );
    cout << ( A.m[1][1] + A.m[1][2] + A.m[1][3] ) % mod << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}