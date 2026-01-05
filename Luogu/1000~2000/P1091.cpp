#include<bits/stdc++.h>
using namespace std;

const int maxn = 100 + 50;

int t[maxn];
int dp1[maxn];
int dp2[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> t[i];
        dp1[i] = dp2[i] = 1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j < i; ++ j )
        {
            if( t[j] < t[i] )
            {
                dp1[i] = max( dp1[i], dp1[j] + 1 );
            }
        }
    }

    for( int i = n; i >= 1; -- i )
    {
        for( int j = n; j > i; -- j )
        {
            if( t[j] < t[i] )
            {
                dp2[i] = max( dp2[i], dp2[j] + 1 );
            }
        }
    }

    int ans = 1e9;
    for( int i = 2; i <= n; ++ i )
    {
        int tmp = dp1[i] + dp2[i] - 1;
        ans = min( ans, n - tmp );
    }

    cout << ans << '\n';
    return 0;
}