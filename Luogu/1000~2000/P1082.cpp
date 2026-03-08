#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll exgcd( ll a, ll b, ll &x, ll &y )
{
    if( b == 0 ) { x = 1, y = 0; return a; }
    ll d = exgcd( b, a % b, y, x );
    y -= a / b * x;
    return d;
}

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll a, b, x, y;
    cin >> a >> b;

    ll d = exgcd( a, b, x, y );
    if( d != 1 ) { cout << -1 << '\n'; return 0; }
    x = ( x % b + b ) % b;
    cout << x << '\n';

    return 0;
}