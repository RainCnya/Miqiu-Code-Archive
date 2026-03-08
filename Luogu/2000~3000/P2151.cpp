#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxm = 60 + 5;
const int maxsz = 2 * maxm;
const int mod = 45989;

struct Edge { int u, v; } e[maxm << 1];
int cnt = 0;

int n, m, t, st, ed;

struct Matrix {
    ll m[maxsz][maxsz];
    int sz;
    Matrix( int s = 0 ) : sz( s ) { memset( m, 0, sizeof( m ) ); }
    void init( ) { for( int i = 0; i < sz; ++ i ) m[i][i] = 1; }

    friend Matrix operator * ( const Matrix &a, const Matrix &b ) {
        Matrix res( a.sz );
        for( int i = 0; i < res.sz; ++ i ) {
            for( int k = 0; k < res.sz; ++ k ) {
                if( a.m[i][k] == 0 ) continue;
                for( int j = 0; j < res.sz; ++ j )
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
    
    cin >> n >> m >> t >> st >> ed;
    for( int i = 0; i < m; ++ i )
    {
        int u, v; cin >> u >> v;
        e[cnt ++] = { u, v };
        e[cnt ++] = { v, u };
    }

    Matrix T( cnt );

    for( int i = 0; i < cnt; ++ i )
    {
        for( int j = 0; j < cnt; ++ j )
        {
            if( e[i].v == e[j].u && j != (i ^ 1) )
                T.m[i][j] = 1;
        }
    }

    Matrix V( cnt );
    for( int i = 0; i < cnt; ++ i )
    {
        if( e[i].u == st ) V.m[0][i] = 1;
    }

    Matrix res = V * mqpow( T, t - 1 );

    ll ans = 0;
    for( int i = 0; i < cnt; ++ i )
    {
        if( e[i].v == ed ) ans = ( ans + res.m[0][i] ) % mod;
    }

    cout << ans << '\n';
    return 0;
}