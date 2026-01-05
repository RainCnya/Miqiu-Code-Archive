#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const ll inf = 1e18;

ll a[maxn];
ll n, k;

bool check( ll mid )
{
    ll cnt = 0;
    ll sum = 0;
    ll l = 1;
    for( int r = 1; r <= n; ++ r )
    {
        sum += a[r];
        while( l <= r && sum - a[l] >= mid ) 
        {
            sum -= a[l];
            l ++;
        }
        if( sum >= mid )
            cnt += l;
    }

    return cnt >= k;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    while( cin >> n >> k )
    {
        ll sum = 0;
        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i];
            sum += a[i];
        }

        ll l = 0, r = sum + 1;
        ll ans = 0;
        
        while( l <= r )
        {
            ll mid = ( l + r ) >> 1;
            if( check( mid ) ) ans = mid, l = mid + 1;
            else r = mid - 1;
        }

        cout << ans << '\n';
    }
    return 0;
}