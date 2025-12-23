#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

struct Customer {
    ll s, t, x;
} a[maxn];

int n;
ll t;

void solve( )
{
    cin >> n >> t;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i].s >> a[i].t >> a[i].x;
    }    

    int l = 1;
    ll ans = 0;
    ll cur = 0;
    for( int r = 1; r <= n; ++ r )
    {
        cur += a[r].x;
        while( l <= r && ( a[r].s + a[r].t - a[l].s > t ) )
        {
            cur -= a[l].x;
            l ++;
        }
        ans = max( ans, cur );
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
