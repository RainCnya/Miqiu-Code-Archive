#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 50;
const int inf = 1e9;

int dp[maxn];
int a[maxn];
int n, w;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> w;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    dp[0] = 0;
    for( int i = 1; i <= w; ++ i )
    {
        dp[i] = inf;
        for( int j = 1; j <= n; ++ j )
        {
            if( i >= a[j] ) dp[i] = min( dp[i], dp[i - a[j]] + 1 );
        }
    }
    cout << dp[w] << endl;
    return 0;
}