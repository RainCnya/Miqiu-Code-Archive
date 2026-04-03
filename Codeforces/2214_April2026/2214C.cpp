#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n; cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        int a, b, c; cin >> a >> b >> c;
        int x = a ^ b ^ c;
        int m = a + b + c - min({a, b, c}) - max({a, b, c});
        cout << x - m << '\n';
    }
}

int main( )
{
    cin.tie( 0 )->sync_with_stdio( 0 );
    solve( );
    return 0;
}