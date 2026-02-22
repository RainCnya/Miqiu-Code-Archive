#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 20 + 5;

int a[maxn];
int g[maxn][maxn];
int f[maxn];
// f[i] 表示从 i 点往后最多挖几个雷
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i <= n - 1; ++ i )
        for( int j = i + 1; j <= n; ++ j )
            cin >> g[i][j];
    
    int ans = n;
    for( int i = n; i >= 1; -- i )
    {
        f[i] = a[i];
        for( int j = i + 1; j <= n; ++ j )
        {
            if( g[i][j] ) f[i] = max( f[i], f[j] + a[i] );
        }
        if( f[ans] < f[i] ) ans = i;
    }

    cout << ans << ' ';

    for( int i = ans, j = ans + 1; j <= n; ++ j )
    {
        if( g[i][j] && f[i] == f[j] + a[i] )
        {
            cout << j << ' ';
            i = j;
        }
    }

    cout << '\n' << f[ans] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}