#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 50;

int dp[maxn];
int a[maxn];
int x[maxn];
int cnt;

int main()
{	
    int n;
    while( cin >> n )
    {
        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i];
        }

        for( int i = 2; i <= n; ++ i )
        {
            for( int j = 1; j < i; ++ j )
            {
                if( a[j] >= a[i] )
                {
                    dp[i] = max( dp[i], dp[j] + 1 );
                }
            }
        }

        // int ans = 0;
        // for( int i = 1; i <= n; ++ i )
        // {
        //     ans = max( ans, dp[i] );
        // }
        // cout << ans << '\n';

        int cnt = 0;
        for( int i = 1; i <= n; ++ i )
        {
            if( x[cnt] < a[i] )
            {
                cnt ++;
                x[cnt] = a[i];
            }
            else
            {
                int k = lower_bound( x + 1, x + cnt + 1, a[i] ) - x;
                x[k] = a[i];
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}