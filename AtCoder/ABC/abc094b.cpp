#include<bits/stdc++.h>
using namespace std;

int cnt[105];
int pre[105];

int main() {
    int n, m, x;
    cin >> n >> m >> x;   
    for( int i = 1; i <= m; ++ i ) {
        int a;  cin >> a;
        cnt[a] = 1;
    }
    for( int i = 0; i <= n; ++ i ) {
        if( cnt[i] && i != 0 ) {
            pre[i] = pre[i-1] + 1;
        } else {
            pre[i] = pre[i-1];   
        }
    }
    int l = pre[x];
    int r = m - pre[x];
    cout << min( l, r );
    return 0;
}