#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    int n;  cin >> n;
    vector<int> a( n + 1 );
    vector<int> dp( n + 1 );
    int ans = -inf;

    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
        dp[i] = max( a[i], dp[i-1] + a[i] );
        ans = max( ans, dp[i] );
    }

    cout << ans << '\n';
    return 0;
}