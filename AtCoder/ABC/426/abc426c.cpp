#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int sum[maxn];

int main() {
    int n, q;
    cin >> n >> q;
    for( int i = 1; i <= n; ++ i ) {
        sum[i] = 1;
    }
    int last = 1;
    for( int i = 1; i <= q; ++ i ) {
        int x, y;
        cin >> x >> y;
        int res = 0;
        while( last <= x ) {
            res += sum[last];
            sum[y] += sum[last];
            last ++;
        } 
        cout << res << '\n';
    }
    return 0;
}