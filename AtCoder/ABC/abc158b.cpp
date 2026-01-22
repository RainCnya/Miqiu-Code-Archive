#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll cnt = n / ( a + b );
    ll remain = n % ( a + b );
    ll ans = cnt * a;
    if( remain >= a ) {
        ans += a;
    } else {
        ans += remain;
    }
    cout << ans << '\n';
    return 0;
}