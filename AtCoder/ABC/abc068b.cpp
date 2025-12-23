#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;  cin >> n;
    int ans = 0;
    for( int i = 1; (1<<i) <= n; ++ i ) {
        ans ++;
    }
    cout << (1<<ans) << '\n';
    return 0;
}