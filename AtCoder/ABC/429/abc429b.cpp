#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int sum = 0;
    map<int, int> cnt;
    for( int i = 1; i <= n; ++ i ) {
        int x;
        cin >> x;
        sum += x;
        cnt[x] ++;
    }
    if( cnt[sum - m] ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}