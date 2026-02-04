#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2000 + 50;

bitset< maxn > g[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            char c;
            cin >> c;
            if( c == '1' ) g[i].set(j);
        }
        g[i].set(i);
    }

    for( int k = 1; k <= n; ++ k )
    {
        for( int i = 1; i <= n; ++ i )
        {
            if( g[i][k] ) g[i] |= g[k];
        }
    }

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans += g[i].count( );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}