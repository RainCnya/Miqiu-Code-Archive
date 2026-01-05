#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e6 + 50;
const int inf = 1e9;

int a[maxn];
int sum[maxn];
int dif[maxn];

int main() {
    int n, p;
    cin >> n >> p;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    
    for( int i = 1; i <= p; ++ i ) {
        int x, y, z;
        cin >> x >> y >> z;
        dif[x] += z;
        dif[y+1] -= z;
    }

    int minn = inf;
    for( int i = 1; i <= n; ++ i ) {
        sum[i] = sum[i-1] + dif[i];
        a[i] += sum[i];
        minn = min( minn, a[i] );
    }

    cout << minn << '\n';
    return 0;
}