#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p, q;

void solve( )
{
    cin >> p >> q;
    ll val = 3 * p - 2 * q;
    if( val >= 0 && 2 * val <= p + q - 1 ) cout << "Bob" << '\n';
    else cout << "Alice" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}