#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 50 + 5;
const int maxn2 = 250 + 5;
const int maxk = 200 + 5;
const ll inf = 1e18;

ll c[maxn];
int n, m, T, k;
int sz;

struct Mat {
    ll mat[maxn2][maxn2];
    Mat( ) { memset( mat, -0x3f, sizeof (mat) ); }
} pw[31];

// ( max, + )
Mat mul( const Mat &A, const Mat &B )
{
    Mat res;
    for( int i = 1; i <= sz; ++ i )
    {
        for( int k = 1; k <= sz; ++ k )
        {
            if( A.mat[i][k] < 0 ) continue;
            for( int j = 1; j <= sz; ++ j )
            {
                if( B.mat[k][j] < 0 ) continue;
                res.mat[i][j] = max( res.mat[i][j], A.mat[i][k] + B.mat[k][j] );
            }
        }
    }
    return res;
}

void vec_mul( ll *V, const Mat &M )
{
    static ll tmp[maxn2];
    for( int i = 1; i <= sz; ++ i ) tmp[i] = -inf;

    for( int i = 1; i <= sz; ++ i )
    {
        if( V[i] < 0 ) continue;
        for( int j = 1; j <= sz; ++ j )
        {
            if( M.mat[i][j] < 0 ) continue;
            tmp[j] = max( tmp[j], V[i] + M.mat[i][j] );
        }
    }
    
    for( int i = 1; i <= sz; ++ i ) V[i] = tmp[i];
}

struct Festival {
    int t, x, y;
    bool operator < ( const Festival &oth ) const { return t < oth.t; }
} fes[205];

int main( )
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    
    cin >> n >> m >> T >> k;
    sz = 5 * n;
    for( int i = 1; i <= n; ++ i ) cin >> c[i];

    Mat base;
    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= 4; ++ j )
            base.mat[i + j * n][i + (j - 1) * n] = 0;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w; cin >> u >> v >> w;
        base.mat[u][v + (w - 1) * n] = c[v];
    }

    pw[0] = base;
    for( int i = 1; i <= 30; ++ i ) pw[i] = mul( pw[i - 1], pw[i - 1] );

    for( int i = 1; i <= k; ++ i ) cin >> fes[i].t >> fes[i].x >> fes[i].y;
    sort( fes + 1, fes + k + 1 );

    ll V[maxn2];
    for( int i = 1; i <= sz; ++ i ) V[i] = -inf;
    V[1] = c[1];

    int lst = 0;
    fes[k + 1] = { T, 1, 0 };

    for( int i = 1; i <= k + 1; ++ i )
    {
        int dt = fes[i].t - lst;
        for( int p = 30; p >= 0; -- p )
            if( dt >> p & 1 ) vec_mul( V, pw[p] );
        
        if( V[fes[i].x] >= 0 ) V[fes[i].x] += fes[i].y;
        lst = fes[i].t;
    }

    if( V[1] < 0 ) cout << -1 << '\n';
    else cout << V[1] << '\n';
    return 0;
}