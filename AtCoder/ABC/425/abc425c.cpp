#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5 + 50;

ll a[maxn];
ll sum[maxn*2];

int main() {
    int n, q;
    cin >> n >> q;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }   
    for( int i = 1; i <= n; ++ i ) {
        sum[i+n] = sum[i+n-1] + a[i];
    }

    int st = 1;
    for( int i = 1; i <= q; ++ i ) {
        int opt;
        cin >> opt;
        if( opt == 1 ) {
            int c;
            cin >> c;
            st += c;
            st %= n;
            if( st == 0 ) st += n;
        }
        else {
            int l, r;
            cin >> l >> r;
            int nl = l + st - 1;
            int nr = r + st - 1;
            ll res = sum[nr] - sum[nl-1];
            cout << res << '\n';
        }
    }
    return 0;
}