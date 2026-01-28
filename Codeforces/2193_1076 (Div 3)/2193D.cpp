#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

ll a[maxn];
int b[maxn];
int n;

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];
    sort( a + 1, a + n + 1 );

    ll cnt = 0;
    ll ans = 0;
    for( int k = 1; k <= n; ++ k )
    {
        cnt += b[k];
        if( cnt > n ) break;
        ll x = a[n - cnt + 1];
        ans = max( ans, x * k );
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