#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const ll inf = 1e18;
int n, m;
ll w[maxn], v[maxn];
ll l[maxn], r[maxn];
ll sum1[maxn], sum2[maxn];
ll s, ans = inf;

bool check( ll mid ) {
    memset( sum1, 0, sizeof( sum1 ) );
    memset( sum2, 0, sizeof( sum2 ) );
    for( int i = 1; i <= n; ++ i ) {
        if( w[i] >= mid ) {
            sum1[i] = sum1[i-1] + 1;
            sum2[i] = sum2[i-1] + v[i];
        } else {
            sum1[i] = sum1[i-1];
            sum2[i] = sum2[i-1];
        }
    }

    ll res = 0;
    for( int i = 1; i <= m; ++ i ) {
        int ll = l[i], rr = r[i];
        res += ( sum1[rr] - sum1[ll-1] ) * ( sum2[rr] - sum2[ll-1] );
    }
    ans = min( ans, abs( s - res ) );

    return res > s;
}

int main() {
    cin >> n >> m >> s;
    for( int i = 1; i <= n; ++ i ) {
        cin >> w[i] >> v[i];
    }
    for( int i = 1; i <= m; ++ i ) {
        cin >> l[i] >> r[i];
    }
    ll left = 0, right = 1e6;
    while( left <= right ) {
        ll mid = ( left + right ) >> 1;

        if( check( mid ) ) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}