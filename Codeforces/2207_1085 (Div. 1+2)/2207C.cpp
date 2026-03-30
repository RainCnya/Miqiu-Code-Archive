#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2000 + 5;

ll n, h;
ll a[maxn];
ll pre[maxn];
ll suf[maxn];

void solve( )
{
    cin >> n >> h;

    for( int i = 1; i <= n + 1; ++ i ) pre[i] = suf[i] = 0;
    
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i <= n; ++ i )
    {
        vector< ll > nums( n + 1 );

        ll val = a[i];
        for( int j = i; j >= 1; -- j )
        {
            val = max( val, a[j] );
            nums[j] = h - val;
        }

        val = a[i];
        for( int j = i + 1; j <= n; ++ j )
        {
            val = max( val, a[j] );
            nums[j] = h - val;
        }

        ll cur = 0;
        for( int k = 1; k <= n; ++ k )
        {
            cur += nums[k];
            if( i <= k ) pre[k] = max( pre[k], cur );
        }
        cur = 0;
        for( int k = n; k >= 1; -- k )
        {
            cur += nums[k];
            if( k <= i ) suf[k] = max( suf[k], cur );
        }
    }

    ll ans = pre[n];
    for( int k = 1; k <= n; ++ k )
    {
        ans = max( ans, pre[k] + suf[k + 1] );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}