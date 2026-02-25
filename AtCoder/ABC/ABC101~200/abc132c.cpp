#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int main() {
    int n;
    int a[maxn];
    cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    sort( a + 1, a + n + 1 );
    int mid = n / 2;
    int l = a[mid], r = a[mid + 1];
    if( l == r ) {
        cout << 0 << '\n';
    } else {
        cout << r - l << '\n';
    }
    return 0;
}