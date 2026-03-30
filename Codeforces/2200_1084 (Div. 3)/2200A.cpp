#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int ma = -1, cnt = 0;
    int n; cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x; cin >> x;
        if( x > ma ) ma = x, cnt = 1;
        else if( x == ma ) ++ cnt;
    }
    cout << cnt << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}