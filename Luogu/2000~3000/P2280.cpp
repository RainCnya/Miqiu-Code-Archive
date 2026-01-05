#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e3 + 50;
int n, m;

ll sum[maxn][maxn];

int main() {
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) {
        int x, y, v;
        cin >> x >> y >> v;
        sum[x+1][y+1] += v;
    }
    
    for( int i = 1; i <= 5001; ++ i ) {
        for( int j = 1; j <= 5001; ++ j ) {
            sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    ll ans = 0;
    for( int i = m; i <= 5001; ++ i ) {
        for( int j = m; j <= 5001; ++ j ) {
            ll cur = sum[i][j] - sum[i-m][j] - sum[i][j-m] + sum[i-m][j-m];
            ans = max( ans, cur );
        }
    }
    
    cout << ans << '\n';
    return 0;
}