#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;
const int mod = 998244353;

int dp[maxn][4];
string s, t;

int ps[3][2] = { {0, 0}, {0, 1}, {1, 1} };

void solve( )
{
    cin >> s >> t;
    int len = t.length( );
    int l = s.length( );
    string tmp(len - l, '0');
    s = tmp + s;
    
    dp[len][0] = dp[len][1] = dp[len][2] = dp[len][3] = 1;

    for( int i = len - 1; i >= 0; -- i )
    {
        int si = s[i] - '0', ti = t[i] - '0';
        for( int m = 0; m < 4; ++ m )
        {
            ll sum = 0;
            bool ms = ( m >> 1 ) & 1;
            bool mt = ( m >> 0 ) & 1;
            for( auto &p : ps )
            {
                if( ( ms && p[0] < si ) || ( mt && p[1] > ti) ) continue;
                int ns = ms && (p[0] == si), nt = mt && (p[1] == ti);
                int nm = ( ns << 1 ) | nt;
                sum += dp[i + 1][nm];
            }
            dp[i][m] = sum % mod;
        }
    }
    ll tot = dp[0][3];

    ll S = 0, T = 0;
    for( int i = 0; i < len; ++ i ) 
    {
        S = (S * 2 + (s[i] - '0')) % mod;
        T = (T * 2 + (t[i] - '0')) % mod;
    }
    ll diff = (T - S + 1 + mod) % mod;

    ll ans = (2LL * tot - diff + mod) % mod;
    cout << ans << "\n";
}
 
int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}