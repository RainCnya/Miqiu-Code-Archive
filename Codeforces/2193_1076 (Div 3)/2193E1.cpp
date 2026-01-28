#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
const int inf = 1e9;

int a[maxn], dp[maxn];
int n, q;

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) dp[i] = inf;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = i; j <= n; j += i )
        {
            dp[j] = min( dp[j], dp[i] + dp[j / i] );
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( dp[i] == inf ) dp[i] = -1;
        cout << dp[i] << " ";
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}