#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;

int dp[maxn];

int main()
{	
    string s;
    cin >> s;
    int len = s.length( );
    s = " " + s;
    for( int i = 1; i <= len; ++ i )
    {
        if( s[i] == '[' || s[i] == '(' ) continue;
        if( s[i] == ']' && s[i-1 - dp[i-1]] == '[' )
        {
            dp[i] = dp[i-1] + 2 + dp[i-1 - dp[i-1] - 1];
        }
        if( s[i] == ')' && s[i-1 - dp[i-1]] == '(' )
        {
            dp[i] = dp[i-1] + 2 + dp[i-1 - dp[i-1] - 1];
        }
    }

    int ans = -1;
    int end = -1;
    for( int i = 1; i <= len; ++ i )
    {
        if( dp[i] > ans )
        {
            ans = dp[i];
            end = i;
        }
    }

    // cout << ans << '\n';

    for( int i = end - dp[end] + 1; i <= end; ++ i )
    {
        cout << s[i];
    }
    return 0;
}