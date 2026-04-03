#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const ll inf = 2e18;

ll p2( int p ) { return ( p >= 62 ? inf : (1LL << p) ); }

void solve( )
{
    ll x, k; cin >> x >> k;
    vector< int > ans;
    while( k )
    {
        for( int i = 1; i <= x; ++ i )
        {
            ll cnt = p2( x - i );
            if( k <= cnt )
            {
                ans.push_back( i );
                k -= 1, x -= i;
                break;
            }
            else k -= cnt;
        }
    }
    for( int x : ans ) cout << x << " ";
    cout << "\n";
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}