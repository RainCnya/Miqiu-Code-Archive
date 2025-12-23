#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
const ll inf = 1e18;

ll a[maxn], b[maxn];
ll l[maxn], r[maxn];


void solve( )
{
    int n;
    ll k;
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    ll ans = -inf;
    ll sum = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( sum < 0 ) sum = 0;
        sum += a[i];
        ans = max( ans, sum );
    }

    if( k % 2 == 0 )
    {
        cout << ans << '\n';
        return ;
    }

    memset( l, 128, sizeof( l ) );
    memset( r, 128, sizeof( r ) );
    
    for( int i = 1; i <= n; ++ i )
    {
        if( i == 1 ) l[i] = a[i];
        else l[i] = max( a[i], l[i-1] + a[i] );
    }
    for( int i = n; i >= 1; -- i )
    {
        if( i == n ) r[i] = a[i];
        else r[i] = max( a[i], r[i+1] + a[i] );
    }

    for( int i = 1; i <= n; ++ i )
    {
        ll val = a[i] + b[i];
        ll ls = 0, rs = 0;
        if( i > 1 ) ls = l[i-1] > 0 ? l[i-1] : 0;
        if( i < n ) rs = r[i+1] > 0 ? r[i+1] : 0;
        ll res = val + ls + rs;
        ans = max( ans, res );
    }
    cout << ans << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}