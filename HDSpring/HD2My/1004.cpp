#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    ll n, k;
    cin >> n >> k;
    for( int i = 1; i <= n - 2; ++ i ) cout << 1 << ' ';
    cout << 2 << ' ' << n + k << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}