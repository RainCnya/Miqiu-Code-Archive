#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 50;

int dp[maxn];
int a[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    dp[0] = 0, dp[1] = a[1];
    for( int i = 2; i <= n; ++ i )
    {
        dp[i] = min( dp[i-1], dp[i-2] ) + a[i];
    }
    
    cout << min( dp[n-1], dp[n] ) << '\n';
    return 0;
}