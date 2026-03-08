#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll Q, l, r;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> Q;
    while( Q-- )
    {
        cin >> l >> r;
        ll ans = ( l + r ) % 9 * ( r - l + 1 ) % 9 * 5 % 9;
        cout << ans << '\n';
    }

    return 0;
}