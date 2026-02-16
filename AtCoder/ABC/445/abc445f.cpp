#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;
const ll inf = 1e18;

ll n, k;

struct Mat {
    ll mat[maxn][maxn];
    Mat( ) { memset( mat, 0x3f, sizeof (mat) ); }
    Mat mul( const Mat &A, const Mat &B )
    {
        Mat res;
        for( int k = 1; k <= n; ++ k )
        {
            for( int i = 1; i <= n; ++ i )
            {
                if( A.mat[i][k] == inf ) continue;
                for( int j = 1; j <= n; ++ j )
                {
                    if( B.mat[k][j] == inf ) continue;
                    res.mat[i][j] = min( res.mat[i][j], A.mat[i][k] + B.mat[k][j] );
                }
            }
        }
        return res;
    }
    Mat pow( Mat A, ll k )
    {
        Mat res = A;
        while( k )
        {
            if( k & 1 ) res = mul( res, A );
            A = mul( A, A );
            k >>= 1;
        }
        return res;
    }
};

void solve( )
{
    cin >> n >> k;

    Mat c;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            cin >> c.mat[i][j];
        }
    }

    Mat ans = c.pow( c, k - 1 );

    for( int i = 1; i <= n; ++ i )
    {
        cout << ans.mat[i][i] << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}