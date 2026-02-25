#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
const int mod = 998244353;

ll dp[maxn];
ll sum[maxn], diff[maxn];
ll p2[maxn];
int nxt[maxn];
string s;
int n;

void init( )
{
    p2[0] = 1;
    for( int i = 1; i < maxn; ++ i ) p2[i] = ( p2[i - 1] * 2 ) % mod;
}

void solve( )
{
    cin >> n >> s;
    s = ' ' + s;

    for( int i = 0; i <= n + 2; ++ i ) dp[i] = diff[i] = 0;

    sum[0] = 0;
    for( int i = 1; i <= n; ++ i ) 
    {
        int cur = ( s[i] == '(' ? 1 : -1 );
        sum[i] = sum[i - 1] + cur;
    }

    nxt[n + 1] = n + 1;
    for( int i = n; i >= 1; -- i )
    {
        if( sum[i] <= 1 ) nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }

    ll ans = 0;
    ll suml = 0, sumr = 0;

    for( int i = 1; i <= n; ++ i )
    {
        suml = ( suml - diff[i] + mod ) % mod;
        dp[i] = ( 1 + suml + sumr ) % mod;

        if( s[i] == '(' ) 
        {
            ans = ( ans + p2[i - 1] ) % mod;
            suml = ( suml + dp[i] ) % mod;
            diff[nxt[i] + 1] = ( diff[nxt[i] + 1] + dp[i] ) % mod;
        }
        else 
        {
            ans = ( ans + dp[i] ) % mod;
            sumr = ( sumr + dp[i] ) % mod;
        }
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init( );
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}