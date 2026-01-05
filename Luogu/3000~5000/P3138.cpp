#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 1e3 + 50;

struct node{
    int x, y, id;
}pos[maxn];

int n, sum[maxn][maxn];
int x[maxn], y[maxn];

bool cmpx( node a, node b ) {
    return a.x < b.x;
}

bool cmpy( node a, node b ) {
    return a.y < b.y;
}

int calc( int i, int j ) {
    int res1 = sum[i][j];
    int res2 = sum[n][n] - sum[i][n] - sum[n][j] + sum[i][j];
    int res3 = sum[i][n] - sum[i][j];
    int res4 = sum[n][j] - sum[i][j];
    return max( max( res1, res2 ), max( res3, res4 ) );
}

int main() {
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int _x, _y;
        cin >> pos[i].x >> pos[i].y;
        pos[i].id = i;
    }

    sort( pos+1, pos+n+1, cmpx );
    for( int i = 1; i <= n; ++ i ) {
        x[pos[i].id] = i;
    }
    
    sort( pos+1, pos+n+1, cmpy );
    for( int i = 1; i <= n; ++ i ) {
        y[pos[i].id] = i;
    }

    for( int i = 1; i <= n; ++ i )
        sum[ x[i] ][ y[i] ] ++;

    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= n; ++ j )
            sum[i][j] += sum[i-1][j];
    
    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= n; ++ j )
            sum[i][j] += sum[i][j-1];

    int ans = inf;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
            ans = min( ans, calc( i, j ) );
    }

    cout << ans << '\n';
    return 0;
}