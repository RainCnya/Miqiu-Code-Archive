#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int a[maxn];

int main() {
    int n;  cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    int cur = 1;
    for( int i = 1; i <= n ; ++ i ) {
        cur = a[cur];
        if( cur == 2 ) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << "-1" << '\n';
    return 0;
}