#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;
const int inf = 1e9;

int a[maxn<<1];

int main() {
    int k, n;
    cin >> k >> n;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
        a[n+i] = a[i] + k;
    }
    int minn = inf;
    for( int i = 1; i <= n; ++ i ) {
        minn = min( minn, a[i+n-1] - a[i] );
    }
    cout << minn << '\n';
    return 0;
}