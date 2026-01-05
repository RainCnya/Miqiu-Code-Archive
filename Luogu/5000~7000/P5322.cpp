// 分组背包
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int maxm = 2e4 + 50;

int s, n, m;
int a[maxn][maxn];
int dp[maxm];

int main()
{	
    cin >> s >> n >> m;
    for( int j = 1; j <= s; ++ j )
    {
        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i][j];
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        sort( a[i] + 1, a[i] + s + 1 );
        for( int j = 1; j <= s; ++ j )
        {
            a[i][j] = a[i][j] * 2 + 1;
        }
    }

    for( int k = 1; k <= n; ++ k )
    {
        for( int j = m; j >= 0; -- j )
        {
            for( int i = 1; i <= s; ++ i )
            {
                if( j >= a[k][i] )
                    dp[j] = max( dp[j], dp[ j - a[k][i] ] + i * k );
            }
        }
    }

    cout << dp[m] << '\n';
    return 0;
}