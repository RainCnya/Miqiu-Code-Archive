#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;

    ll ans = n * k;    
    for( ll l = 1, r; l <= n; l = r + 1 )
    {
        ll val = k / l;
        if( val != 0 ) r = min( k / val, n );
        else r = n;
        ans -= val * ( l + r ) * ( r - l + 1 ) / 2;
    }
    cout << ans << '\n';
    return 0;
}