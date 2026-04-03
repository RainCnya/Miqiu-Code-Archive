#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int mod = 676767677;

ll x, y;

void solve( )
{
    cin >> x >> y;
    
    ll t = abs( x - y );
    ll res = 1;
    for( ll i = 2; i <= t / i; ++ i )
    {
        if( t % i == 0 )
        {
            ll cnt = 0;
            while( t % i == 0 ) t /= i, cnt ++;
            res = ( res * ( cnt + 1 ) ) % mod;
        }
    }
    if( t > 1 ) res = ( res * 2 ) % mod;
    
    cout << res << '\n';

    for( int i = 1; i <= x; ++ i ) cout << 1 << ' ';
    for( int i = 1; i <= y; ++ i ) cout << -1 << ' ';
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}