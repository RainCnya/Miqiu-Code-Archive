#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 50;
const int inf = 1e9;

int n, m, p;
int v[maxn][maxn];
int w[maxn];
long long dp[maxn];

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> p;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> v[i][j];
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> w[i];
    }

    for( int j = 1; j <= m; ++ j )
    {
        dp[j] = -inf;
    }
    dp[0] = 0;

    for( int j = 0; j < m; ++ j )
    {
        if( dp[j] == -inf ) continue;
        for( int i = 1; i <= n; ++ i )
        {
            int cur = dp[j] - w[i];
            int st = i;         // start
            int t = j + 1;      // time
            for( int k = 1; k <= p; ++ k )
            {
                if( t > m ) break;
                cur += v[st][t];
                if( cur > dp[t] ) dp[t] = cur;
                st ++;
                if( st > n ) st = 1;
                t ++;
            }
        }
    }

    cout << dp[m] << '\n';
    return 0;
}