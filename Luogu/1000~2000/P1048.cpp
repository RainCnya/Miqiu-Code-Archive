// 01背包
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 50;
int v[maxn], w[maxn];
int dp[maxn];
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
        for( int j = W; j >= w[i]; -- j )
        {
            dp[j] = max( dp[j], dp[ j - w[i] ] + v[i] );
        }
    }

    cout << dp[W];
    return 0;
}