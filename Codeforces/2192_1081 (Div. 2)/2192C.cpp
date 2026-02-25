#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int n;
ll h, k;
ll Sum[maxn], suf[maxn], pre[maxn];
ll a[maxn];

void solve( )
{
    cin >> n >> h >> k;
    
    ll s = 0;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        s += a[i];
    }

    ll cnt = ( h - 1 ) / s;
    ll hh = h - cnt * s;

    for( int i = 1; i <= n; ++ i ) Sum[i] = Sum[i-1] + a[i];

    suf[n + 1] = 0;
    for( int i = n; i >= 1; -- i ) suf[i] = max( suf[i + 1], a[i] );

    pre[0] = 2e18;
    for( int i = 1; i <= n; ++ i ) pre[i] = min( pre[i - 1], a[i] );

    ll ans = n;
    for( int i = 1; i <= n; ++ i )
    {
        ll cur = Sum[i];
        if( i < n )
        {
            ll delta = suf[i + 1] - pre[i];
            if( delta > 0 ) cur += delta;
        }

        if( cur >= hh )
        {
            ans = i;
            break;
        }
    }

    cout << cnt * ( n + k ) + ans << '\n';
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