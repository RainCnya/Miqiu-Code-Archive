#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 5;

ll f[maxn][maxn];
ll g[maxn][maxn][maxn];
int n, m;

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        ll w, l, r;
        cin >> w >> l >> r;
        for( int k = l; k <= r; ++ k ) g[l][r][k] = max( g[l][r][k], w );
    }

    for( int len = 1; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;
            for( int k = l; k <= r; ++ k )
            {
                if( l < k ) g[l][r][k] = max( g[l][r][k], g[l+1][r][k] );
                if( k < r ) g[l][r][k] = max( g[l][r][k], g[l][r-1][k] );
            }
        }
    }

    for( int len = 1; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;
            for( int k = l; k <= r; ++ k )
            {
                f[l][r] = max( f[l][r], f[l][k-1] + f[k+1][r] + g[l][r][k] );            
            }
        }
    }
    cout << f[1][n] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}