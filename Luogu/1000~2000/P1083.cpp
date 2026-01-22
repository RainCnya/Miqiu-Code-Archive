#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 50;

ll r[maxn];
ll dif[maxn], sum[maxn];
ll d[maxn], s[maxn], t[maxn];

int n, m;

bool check( int x ) {
    memset( dif, 0, sizeof( dif ) );
    for( int i = 1; i <= x; ++ i ) {
        dif[ s[i] ] += d[i];
        dif[ t[i] + 1 ] -= d[i];
    }
    for( int i = 1; i <= n; ++ i ) {
        sum[i] = sum[i-1] + dif[i];
        if( sum[i] > r[i] ) return 0;
    }
    return 1;
} 

int main() {
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) {
        cin >> r[i];
    }
    for( int i = 1; i <= m; ++ i ) {
        cin >> d[i] >> s[i] >> t[i];
    }
    int ans  = 0;
    if( check( m ) ) {
        cout << 0 << '\n';
        return 0;
    }
    int left = 1, right = m;
    while( left <= right ) {
        int mid = ( left + right ) >> 1;
        if( check( mid ) ) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    cout << -1 << '\n' << ans + 1 << '\n';
    return 0;
}