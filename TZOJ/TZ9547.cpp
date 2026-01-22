#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;

int n, cnt;
int a[maxn], nxt[maxn];
int dp[maxn], sum[maxn];

void solve()
{
    cin >> n;

    a[n + 1] = inf;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    stack<int> stk;
    stk.push( n + 1 );
    for( int i = n; i >= 1; -- i )
    {
        while( a[stk.top( )] < a[i] ) stk.pop( );
        nxt[i] = stk.top( );
        stk.push( i );
    }

    dp[n + 1] = 1;
    sum[n + 1] = 1;
    nxt[0] = 1;

    for( int i = n; i >= 0; -- i )
    {
        dp[i] = ( sum[i + 1] - sum[nxt[i] + 1] + mod ) % mod;
        sum[i] = ( dp[i] + sum[i + 1] ) % mod;
    }

    cout << ( dp[0] + mod ) % mod << endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve( );
    return 0;
}
