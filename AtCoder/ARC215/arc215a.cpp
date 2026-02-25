#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

ll n, k, l;
ll a[maxn];

bool cmp( ll a, ll b ) { return a > b; }

void solve( )
{
    cin >> n >> k >> l;

    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    sort( a + 1, a + n + 1 );

    vector< ll > segs;
    for( int i = 2; i <= n; ++ i ) segs.push_back( a[i] - a[i - 1] );
    sort( segs.begin( ), segs.end( ), cmp );

    // left(x) and right(y)
    ll x = a[1], y = l - a[n];

    ll ans = 0, delta = 0;

    // merge i times
    for( ll i = 0; i <= min( n - 1, k - 1 ); ++ i )
    {
        ll sum = x + y + delta;
        ll cur = ( k - i ) * sum - min( x, y );
        ans = max( ans, cur );
        if( i < (ll)segs.size( ) ) delta += segs[i];
    }

    // all merge
    ll cost = 0;
    for( ll i = 0; i < min( n - 1, k ); ++ i )
    {
        cost += segs[i];
    }
    ans = max( ans, cost / 2 );

    cout << ans << '\n';
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