#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 10007;
const ll maxn = 1e5 + 50;

ll n, m;
ll num[maxn];
ll col[maxn];

ll sum[maxn][2];
ll cnt[maxn][2];

int main() {
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) {
        cin >> num[i];
    }
    for( int i = 1; i <= n; ++ i ) {
        cin >> col[i];
    }
    for( int i = 1; i <= n; ++ i ) {
        int k = i % 2;
        int c = col[i];
        cnt[c][k] ++;
        sum[c][k] = ( sum[c][k] + num[i] ) % mod;
    }
    ll ans = 0;
    for( int i = 1; i <= n; ++ i ) {
        int k = i % 2;
        int c = col[i];
        ans = ans + (i * num[i] * (cnt[c][k] - 2)) % mod;
        ans = ans + (i * sum[c][k]) % mod;
        ans = ans % mod;
    }
    cout << ans % mod << '\n';
    return 0;
}

