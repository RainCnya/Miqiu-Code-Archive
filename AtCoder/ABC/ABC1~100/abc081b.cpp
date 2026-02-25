#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    int minn = inf;
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        int x;
        cin >> x;
        int cur = 0;
        while( x % 2 == 0 ) {
            x /= 2;
            cur ++;
        }
        minn = min( minn, cur );
    }
    cout << minn << '\n';
    return 0;
}