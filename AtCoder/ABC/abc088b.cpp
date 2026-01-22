#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;  cin >> n;
    vector< int > a(n);
    for( int i = 0; i < n; ++ i ) {
        cin >> a[i];
    }
    sort( a.begin(), a.end() );
    int alice = 0, bob = 0;
    for( int i = 0; i < n; i += 2 ) {
        alice += a[i];
    }
    for( int i = 1; i < n; i += 2 ) {
        bob += a[i];
    }
    cout << abs(alice - bob) << '\n';
    return 0;
}