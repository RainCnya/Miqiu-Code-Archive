#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+50;
int a[maxn], sum[maxn];

int main() {
    int n;
    cin >> n;
    
    map<int, int> cnt;
    for( int i = 1; i <= n; ++ i ) {
        int a;
        cin >> a;
        cnt[a] ++;
    }
    long long sum = 0;
    for( const auto& [val, k] : cnt ) {
        if( k < 2 ) continue;
        long long tmp1 = (long long)k * (k - 1) / 2;
        long long tmp2 = n - k;
        sum += tmp1 * tmp2;
    }
    cout << sum;
    return 0;
}