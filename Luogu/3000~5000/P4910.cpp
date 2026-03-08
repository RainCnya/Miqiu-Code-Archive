#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const int mod = 1e9 + 7;

int L = 2;
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

void solve( )
{
    ll n;
    cin >> n;
    ll ans = 0;

    A.m[1][1] = A.m[1][2] = A.m[2][1] = 1;
    Matrix M = mqpow( A, n - 1 );

    ll cur0 = 1, cur1 = 0;
    ll res1 = M.m[1][1] * cur1 + M.m[1][2] * cur0 % mod;
    ll res0 = M.m[2][1] * cur1 + M.m[2][2] * cur0 % mod;
    ans = ( ans + res1 ) % mod;
    
    cur0 = 0, cur1 = 1;
    res1 = M.m[1][1] * cur1 + M.m[2][1] * cur0 % mod;
    res0 = M.m[2][1] * cur1 + M.m[2][2] * cur0 % mod;
    ans = ( ans + res1 + res0 ) % mod;

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}