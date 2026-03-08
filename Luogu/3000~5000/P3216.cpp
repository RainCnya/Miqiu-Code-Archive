#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxsz = 5;
const int maxn = 100 + 5;

ll dp[maxn];
ll n, mod;

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

ll qpow( ll a, ll k ) {
    ll res = 1;
    for( ; k; k >>= 1, a = a * a % mod )
        if( k & 1 ) res = res * a % mod;
    return res;
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    cin >> n >> mod;

    ll ans[4] = { 0, 0, 0, 1 };
    
    for( ll d = 1, st = 1; st <= n; d ++, st *= 10 )
    {
        ll ed;
        if( st > n / 10 ) ed = n;
        else ed = st * 10 - 1;

        ll cnt = ed - st + 1;

        Matrix T( 3 );
        T.m[1][1] = qpow( 10, d );
        T.m[1][2] = 1; T.m[1][3] = 1;
        T.m[2][1] = 0; T.m[2][2] = 1; T.m[2][3] = 1;
        T.m[3][1] = 0; T.m[3][2] = 0; T.m[3][3] = 1;
        T = mqpow( T, cnt );
        
        ll nxt[4] = { 0, 0, 0, 0 };
        for( int i = 1; i <= 3; ++ i )
            for( int j = 1; j <= 3; ++ j )
                nxt[i] = ( nxt[i] + ans[j] * T.m[i][j] ) % mod;
        
        for( int i = 1; i <= 3; ++ i ) ans[i] = nxt[i];
        if( st > n / 10 ) break;
    }

    cout << ans[1] % mod << '\n';
    return 0;
}