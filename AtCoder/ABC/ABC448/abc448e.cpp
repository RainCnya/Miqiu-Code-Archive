#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxsz = 3;

ll mod = 10007;
int k, m;

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

void solve( )
{
    cin >> k >> m;

    mod = mod * m;

    ll res = 0;
    for( int i = 1; i <= k; ++ i )
    {
        ll c, l;
        cin >> c >> l;
        Matrix T( 2 );
        T.m[1][1] = 10, T.m[1][2] = c;
        T.m[2][1] = 0, T.m[2][2] = 1;

        T = mqpow( T, l );

        res = ( T.m[1][1] * res + T.m[1][2] * 1 ) % mod;
    }   
    cout << res / m << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}