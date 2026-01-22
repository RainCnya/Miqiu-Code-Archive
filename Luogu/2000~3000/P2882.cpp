#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5005;
const int inf = 1e9;

int n;
int a[maxn];
int dif[maxn];
int sum[maxn];

int main() {
    cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        char c;
        cin >> c;
        if( c == 'B' ) a[i] = 0;
        else a[i] = 1;
    }

    int ansk = 0, ansm = inf;
    for( int k = 1; k <= n; ++ k ) {
        memset( dif, 0, sizeof( dif ) );
        int cur = 0;
        int cnt = 0;
        bool ok = 1;

        for( int i = 1; i <= n; ++ i ) {
            cur += dif[i];
            int tmp = ( a[i] + cur ) % 2;
            if( tmp == 0 ) {
                if( i + k - 1 > n ) {
                    ok = 0;
                    break;
                }
                cnt ++;
                dif[i] ++;
                dif[i+k] --;
                cur ++;
            }
        }
        
        if( ok && cnt < ansm ) {
            ansk = k;
            ansm = cnt;
        }
    }
    cout << ansk << ' ' << ansm << '\n';
    return 0;
}