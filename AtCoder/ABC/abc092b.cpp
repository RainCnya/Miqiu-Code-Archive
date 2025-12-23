#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a( n + 1 );
    long long ans = 0;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
        ans += ( d + a[i] - 1 ) / a[i];
    }
    ans += x;
    cout << ans << '\n';
    return 0;
}