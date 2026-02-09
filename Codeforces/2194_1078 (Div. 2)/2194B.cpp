#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

ll a[maxn];
int n;
ll x, y;

void solve( )
{
    cin >> n >> x >> y;

    ll cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        cnt += a[i] / x;
    }

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ll cur = cnt - a[i] / x;
        ll res = a[i] + cur * y;
        ans = max( ans, res );
    }
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