#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k;

ll qpow( ll a, ll k ) 
{
    if( a == 0 ) return 0;
    ll res = 1;
    for (int i = 0; i < k; ++ i ) 
    {
        if (res > n / a) return n + 1;
        res *= a;
    }
    return res;
}

void solve( )
{
    cin >> n >> k;

    if( k > 30 ) {
        cout << 1 << '\n';
        return;
    }

    ll l = 1, r = min( n, 40000ll );
    ll ans = 1;
    while( l <= r )
    {
        ll mid = ( l + r ) >> 1;
        if( mid == 0 ) { l = 1; continue; }
        if( qpow( mid, k ) <= n ) ans = mid, l = mid + 1;
        else r = mid - 1;
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