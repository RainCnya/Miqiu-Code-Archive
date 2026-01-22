// 完全背包
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 50;
const int maxw = 1e7 + 50;
int w[maxn], v[maxn];
long long dp[maxw];
int W, n;

int main()
{	
    cin >> W >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> w[i] >> v[i];
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = w[i]; j <= W; ++ j )
        {
            dp[j] = max( dp[j], dp[ j - w[i] ] + v[i] );
        }
    }
    
    cout << dp[W];
    return 0;
}