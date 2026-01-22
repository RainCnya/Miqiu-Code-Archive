#include<bits/stdc++.h>
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for( int i = 1; i <= n; ++ i ) {
        int x;  cin >> x;
        ans += min( x, k - x ) * 2;
    }
    cout << ans;
    return 0;
}