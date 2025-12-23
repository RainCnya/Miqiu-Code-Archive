#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
int n, m;
ll dif[maxn];
ll sum[maxn];
ll p[maxn];

int main() {
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i ) {
        cin >> p[i];
    }

    for( int i = 1; i < m; ++ i ) {
        ll u = min( p[i], p[i+1] );
        ll v = max( p[i], p[i+1] );
        dif[u] ++, dif[v] --;
    }

    for( int i = 1; i <= n; ++ i ) {
        sum[i] = sum[i-1] + dif[i];
    }

    ll ans = 0;
    for( int i = 1; i <= n - 1; ++ i ) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll tmp = min( a * sum[i], b * sum[i] + c );
        ans += tmp;
    }

    cout << ans << '\n';
    return 0;
}