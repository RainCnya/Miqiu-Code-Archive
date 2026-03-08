#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxm = 6720 + 5;
const int maxn = 1e6 + 5;
const int mod = 998244353;

int dp[maxm][maxm];
// dp[i][j] 第 i 个因数 用 前 j 个因数 组成的方案数
ll fac[maxm];
int pos1[maxn], pos2[maxn], cnt;
ll n, sq;

int get( ll x )
{
    if( x <= sq ) return pos1[x];
    else return pos2[n / x];
}

void solve( )
{
    cin >> n;
    sq = (ll)sqrt( n );
    cnt = 0;
    for( ll i = 1; i * i <= n; ++ i )
    {
        if( n % i == 0 )
        {
            fac[++ cnt] = i;
            if( i * i != n ) fac[++ cnt] = n / i;
        }
    }
    sort( fac + 1, fac + cnt + 1 );

    for( int i = 1; i <= cnt; ++ i )
    {
        if( fac[i] <= sq ) pos1[ fac[i] ] = i;
        else pos2[ n / fac[i] ] = i;
        for( int j = 1; j <= cnt; ++ j ) dp[i][j] = 0;
    }

    for( ll j = 0; j <= cnt; ++ j ) dp[1][j] = 1;

    for( ll j = 2; j <= cnt; ++ j )
    {
        ll f = fac[j];
        for( ll i = 2; i <= cnt; ++ i )
        {
            dp[i][j] = dp[i][j - 1];
            if( fac[i] % f == 0 )
                dp[i][j] = ( dp[i][j] + dp[ get( fac[i] / f ) ][j-1] ) % mod;
        }
    }
    ll ans = dp[cnt][cnt] - 1;
    cout << ( ans + mod ) % mod << '\n';
}

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}