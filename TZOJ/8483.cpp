#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 50;

int v[maxn], dp[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 0; i <= n; ++ i )
    {
        cin >> v[i];
    }
    
    dp[0] = v[0], dp[1] = v[1];
    for( int i = 2; i <= n; ++ i )
    {
        dp[i] = min( dp[i-1], dp[i-2] ) + v[i];
    }

    cout << min(dp[n], dp[n-1]) << '\n';
    return 0;
}