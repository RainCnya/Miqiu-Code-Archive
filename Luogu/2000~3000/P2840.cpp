#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;
const int mod = 1e9 + 7;

int f[maxn], a[maxn];
int n, w;
// f[i] 表示凑够 i 元的方案数

void solve( )
{
    cin >> n >> w;
    
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    f[0] = 1;
    for( int i = 1; i <= w; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            if( i >= a[j] ) f[i] = ( f[i] + f[i - a[j]] ) % mod;
        }
    }
    cout << f[w] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}