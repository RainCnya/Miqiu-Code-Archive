#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 505;
const int inf = 1e9;
int r, c, a, b;
int arr[maxn][maxn];
int sum[maxn][maxn];

bool check( int mid ) {
    int last = 0, tot = 0;
    for( int i = 1; i <= r; ++ i ) {
        int s = 0, cnt = 0;
        for( int j = 1; j <= c; ++ j ) {
            s += sum[i][j] - sum[last][j];
            if( s >= mid ) {
                cnt ++;
                s = 0;
            }
        }
        if( cnt >= b ) {
            last = i;
            tot ++;
        }
    }
    return tot >= a;
}

int main() {
    cin >> r >> c;
    cin >> a >> b;
    for( int i = 1; i <= r; ++ i ) {
        for( int j = 1; j <= c; ++ j ) {
            cin >> arr[i][j];
            sum[i][j] = sum[i-1][j] + arr[i][j];
        }
    }

    int ans = 0;
    int left = 0, right = inf;
    while( left <= right ) {
        int mid = ( left + right ) >> 1;
        if( check( mid ) ) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }  
    }
    cout << ans << '\n';
    return 0;
}