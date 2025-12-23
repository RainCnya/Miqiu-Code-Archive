#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1005;
int n, m;   
int mat[maxn][maxn];
int dif[maxn][maxn];

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
    for( int i = 1; i <= n; ++ i ) {
        for( int j = 1; j <= n; ++ j ) {
            mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + dif[i][j];
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}