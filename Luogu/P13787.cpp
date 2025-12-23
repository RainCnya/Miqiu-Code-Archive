#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5005;
int n, m;   
ll mat[maxn][maxn];
ll dif[maxn][maxn];

int main() {
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i ) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        dif[x1][y1] += 1;
        dif[x2+1][y2+1] ++;
        dif[x2+1][y1] --;
        dif[x1][y2+1] --;
    }
    ll ans = 0;
    for( int i = 1; i <= n; ++ i ) {
        for( int j = 1; j <= n; ++ j ) {
            mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + dif[i][j];
            ans += (i + j) ^ mat[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}