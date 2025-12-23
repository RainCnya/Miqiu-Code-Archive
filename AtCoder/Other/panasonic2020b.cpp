#include<bits/stdc++.h>
using namespace std;

int main() {
    long long h, w;
    cin >> h >> w;
    long long ans = 0;
    if( h == 1 || w == 1 ) {
        ans = 1;
    } else if( h % 2 == 1 ) {
        ans = w * ( h / 2 ) + (w + 1) / 2;
    } else {
        ans = w * ( h / 2 );
    }
    cout << ans << '\n';
    return 0;
}