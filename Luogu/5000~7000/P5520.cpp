#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_A( int n, int m, int mod )
{
    ll res = 1;
    for( int i = n; i >= ( n - m + 1 ); -- i )
        res = res * i % mod;
    return res;
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    ll type, n, m, p;
    cin >> type >> n >> m >> p;
    
    ll ans = get_A( n - m + 1, m, p );

    cout << ans << '\n';
    return 0;
}