#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    ll d = __gcd( a + b, a - b );
    ll d1 = __gcd( a, b );
    if( (x + y) % d == 0 && x % d1 == 0 && y % d1 == 0 ) { cout << "Y" << "\n"; return ; }
    cout << "N" << "\n";
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}