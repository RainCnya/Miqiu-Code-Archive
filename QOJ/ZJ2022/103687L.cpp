#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e6 + 5;

ll a[maxn];
ll s[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; ++ i )
    {
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0;
    ll l = 1;
    for( ll r = 1; r <= n; ++ r )
    {
        while( l < r && a[l] * r <= s[r] ) l ++;
        ans = max( ans, r - l + 1 );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}