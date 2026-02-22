#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;
const int mod = 998244353;

vector< int > pos[maxn];
ll sum[maxn];
ll dp[maxn];
int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )  cin >> a[i];

    sum[0] = dp[0] = 1;

    for( int i = 1; i <= n; ++ i )
    {
        int x = a[i];
        pos[x].push_back( i );

        int cnt = pos[x].size( );

        if( cnt >= x )
        {
            int r = pos[x][cnt - x];
            int l = 0;
            if( cnt - x > 0 ) l = pos[x][cnt - x - 1];
            
            ll cur = sum[r - 1];
            if( l != 0 ) cur = ( cur - sum[l] + mod ) % mod;

            dp[i] = cur;
        }

        sum[i] = ( sum[i - 1] + dp[i] ) % mod;
    }

    ll ans = ( sum[n] - 1 + mod ) % mod;
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}