#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    ll l, a, b;
    cin >> l >> a >> b;
    ll g = __gcd( b, l );

    cout << ( l - g ) + ( a % g ) << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
