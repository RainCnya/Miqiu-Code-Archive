#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

ll a[maxn];

ll n, m, q;
ll x, y, g;

ll lcm( ll a, ll b ) { return a / __gcd( a, b ) * b; }

void solve( )
{
    cin >> n >> m >> q;
    for( int i = 1; i <= n; ++ i ) a[i] = 1;
    
    for( int i = 1; i <= m; ++ i )
    {
        cin >> x >> y >> g;
        a[x] = lcm( a[x], g );
        a[y] = lcm( a[y], g );
    }

    for( int i = 1; i <= q; ++ i )
    {
        cin >> x >> y;
        cout << __gcd( a[x], a[y] ) << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}