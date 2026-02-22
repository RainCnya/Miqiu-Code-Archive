#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
const int maxw = 1e4 + 5;
const int mod = 1e9 + 7;

int f[maxn][maxw];
// f[i][j] 表示前 i 种纸币凑够 j 元的方案数
int a[maxn];
int n, w;

void solve( )
{
    cin >> n >> w;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    f[0][0] = 1;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 0; j <= w; ++ j )
        {
            f[i][j] = f[i-1][j];

            if( j >= a[i] ) f[i][j] = ( f[i][j] + f[i][j - a[i]] ) % mod;
        }
    }
    cout << f[n][w] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}