#include<bits/stdc++.h>
using namespace std;

const int maxn = 25;

int b[maxn];

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for( int i = 1; i <= m; ++ i ) {
        cin >> b[i];
    }
    int cnt = 0;
    for( int i = 1; i <= n; ++ i ) {
        int sum = 0;
        for( int j = 1; j <= m; ++ j ) {
            int x;
            cin >> x;
            sum += x * b[j];
        }
        if( sum + c > 0 ) {
            cnt ++;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}