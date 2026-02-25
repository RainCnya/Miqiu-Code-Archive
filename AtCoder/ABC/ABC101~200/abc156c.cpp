#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
const int inf = 1e9;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    long long ans = inf;
    for( int k = 1; k <= 100; ++ k ) {
        long long tmp = 0;
        for( int i = 1; i <= n; ++ i ) {
            tmp += (a[i] - k) * (a[i] - k);
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
    return 0;
}