#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
const ll inf = 1e18;

ll n, m;

void solve( )
{
    cin >> n >> m;

    if( m % n == 0 )
    {
        cout << 0 << '\n';
        return ;
    }
    if( m == 1 )
    {
        cout << n - 1 << '\n';
        return ;
    }

    ll ans = inf;
    ll m1 = m - 1;
    for( ll l = 1, r; l <= n; l = r + 1 )
    {
        ll val = m1 / l;
        if( val == 0 ) r = n;
        else r = min( n, m1 / val );

        ll cost = n + val * l - m;
        ans = min( ans, cost );
        
        if( val == 0 ) break;
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}