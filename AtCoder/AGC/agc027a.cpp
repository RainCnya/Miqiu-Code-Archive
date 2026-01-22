#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a( n );
    for( int i = 0; i < n; ++ i ) {
        cin >> a[i];
    }
    sort( a.begin( ), a.end( ) );
    if( x < a[0] ) {
        cout << 0 << '\n';
        return 0;
    }
    int cnt = 0;
    long long remain = x;
    for( int i = 0; i < n; ++ i ) {
        if( remain >= a[i] ) {
            remain -= a[i];
            cnt ++;
        }
    }
    if( remain > 0 && cnt == n ) {
        cnt --;
    }
    cout << cnt << '\n';
    return 0;
}