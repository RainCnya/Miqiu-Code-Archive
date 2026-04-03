#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    ll n, m;
    cin >> n >> m;
    if( n & 1 || m & 1 ) cout << ( n * m + 1 ) / 2 << '\n';
    else cout << max( n * (m - 2) / 2, m * (n - 2) / 2 ) << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}