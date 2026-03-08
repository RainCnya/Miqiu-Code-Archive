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

void solve( )
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll x, y;
    ll d = exgcd( a, b, x, y );

    if( c % d != 0 ) { cout << -1 << "\n"; return; }
    
    x *= c / d, y *= c / d;
    ll dx = b / d, dy = a / d;

    ll xmin = ( x % dx + dx ) % dx;
    if( xmin == 0 ) xmin = dx;
    ll ymax = ( c - a * xmin ) / b;

    if( ymax <= 0 )
    {
        ll ymin = ( y % dy + dy ) % dy;
        if( ymin == 0 ) ymin = dy;
        cout << xmin << " " << ymin << '\n';
    }
    else 
    {
        ll ymin = ( y % dy + dy ) % dy;
        if( ymin == 0 ) ymin = dy;
        ll xmax = ( c - b * ymin ) / a;
        if( xmax == 0 ) xmax = dx;

        ll cnt = ( xmax - xmin ) / dx + 1;
        cout << cnt << " " << xmin << " " << ymin << " " << xmax << " " << ymax << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}