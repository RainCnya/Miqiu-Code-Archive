#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 50;

ll a[maxn];
ll b[maxn];
int n, q;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1 );

    for( int i = 1; i <= n; ++ i )
    {
        b[i] = a[i] - i;
    }

    for( int i = 1; i <= q; ++ i )
    {
        ll x, y;
        cin >> x >> y;

        int cnt = lower_bound( a + 1, a + n + 1, x ) - a;

        ll miss = x - cnt ;
        ll k = y + miss;

        int pos = lower_bound( b + 1, b + n + 1, k ) - b;
        ll ans = k + ( pos - 1 );

        cout << ans << '\n'; 
    }

    return 0;
}