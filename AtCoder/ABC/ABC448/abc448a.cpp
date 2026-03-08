#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    int n, x, a;
    cin >> n >> x;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a;
        if( a < x ) x = a, cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}