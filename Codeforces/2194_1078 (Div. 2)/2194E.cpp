#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

int n, m;

void solve( )
{
    cin >> n >> m;

    vector< vector< ll > > a( n + 5, vector< ll >( m + 5 ) );
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> a[i][j];
        }
    }

    vector< vector< ll > > pre( n + 5, vector< ll >( m + 5, -inf ) );
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            if( i == 1 && j == 1 ) pre[i][j] = a[i][j];
            else pre[i][j] = max( pre[i][j - 1], pre[i - 1][j] ) + a[i][j];
        }
    }

    vector< vector< ll > > suf( n + 5, vector< ll >( m + 5, -inf ) );
    for( int i = n; i >= 1; -- i )
    {
        for( int j = m; j >= 1; -- j )
        {
            if( i == n && j == m ) suf[i][j] = a[i][j];
            else suf[i][j] = max( suf[i][j + 1], suf[i + 1][j] ) + a[i][j];
        }
    }

    vector< vector< ll > > dp( n + 5, vector< ll >( m + 5, inf ) );

    vector< ll > mx1( n + m + 1, -inf ), mx2( n + m + 1, -inf );
    vector< ll > cnt( n + m + 1, 0 );

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            int idx = i + j - 1;
            dp[i][j] = pre[i][j] + suf[i][j] - a[i][j];

            if( dp[i][j] > mx1[idx] )
            {
                mx2[idx] = mx1[idx];
                mx1[idx] = dp[i][j];
                cnt[idx] = 1;
            }
            else if( dp[i][j] == mx1[idx] )
            {
                cnt[idx] ++;
            }
            else if( dp[i][j] > mx2[idx] )
            {
                mx2[idx] = dp[i][j];
            }
        }
    }

    ll ans = inf;

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            int idx = i + j - 1;

            ll mx = mx1[idx];
            if( dp[i][j] == mx1[idx] && cnt[idx] == 1 ) mx = mx2[idx];

            ll cur = max( mx, dp[i][j] - 2 * a[i][j] );
            ans = min( ans, cur );
        }
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}