#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calc( int x, int y, int cur )
{
    if( x == y ) return cur;
    if( y / x >= 2 ) return cur;
    else return calc( y - x, x, cur ^ 1 );
}

void solve( )
{
    int a, b;
    cin >> a >> b;
    if( a > b ) swap( a , b );
    
    if( calc( a, b, 0 ) == 0 ) cout << "Stan wins" << '\n';
    else cout << "Ollie wins" << '\n';
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
