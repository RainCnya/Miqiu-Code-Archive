#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 5;
const int maxv = 2e4 + 5;
const int mod = 998244353;

int f[maxn][maxv << 1];
int h[maxn];
int n;

int main( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> h[i];

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j < i; ++ j )
        {
            int d = h[i] - h[j] + maxv;
            f[i][d] = ( f[i][d] + f[j][d] + 1 ) % mod;
            ans = ( ans + (ll)f[j][d] + 1 ) % mod;
        }
    }

    cout << ( ans + n ) % mod << '\n';
    return 0;
}