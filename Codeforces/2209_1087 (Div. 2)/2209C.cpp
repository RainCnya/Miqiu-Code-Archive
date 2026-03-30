#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

int ask( int x, int y )
{
    cout << "? " << x << " " << y << endl;
    int res; cin >> res;
    return res;
}

void ans( int x )
{
    cout << "! " << x << endl;
}

void solve( )
{
    cin >> n;

    if( ask( 1, 2 ) ) { ans( 1 ); return; }
    if( ask( 2, 3 ) ) { ans( 2 ); return; }
    if( ask( 3, 1 ) ) { ans( 3 ); return; }

    for( int i = 4; i <= 2 * n - 1; i += 2 )
    {
        if( ask( i, i + 1 ) == 1 ) { 
            ans( i ); 
            return; 
        }
    }
    ans( 2 * n );
}

int main( )
{
    // ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}