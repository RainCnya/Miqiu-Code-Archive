#include<bits/stdc++.h>
using namespace std;

double v[55];

int main() {
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        cin >> v[i];
    }
    sort( v + 1, v + n + 1 );
    double ans = v[1];
    for( int i = 2; i <= n; ++ i ) {
        ans = ( ans + v[i] ) / 2.0;
    }
    cout << ans << '\n';
    return 0;
}