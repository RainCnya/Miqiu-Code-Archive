#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 50;

int a[maxn];
int dp[maxn];
int from[maxn];
int n;

int main()
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        dp[i] = 1;
        from[i] = -1;
    }

    int ans = 0;
    int end = -1;

    for( int i = 2; i <= n; ++ i )
    {
        for( int j = 1; j < i; ++ j )
        {
            if( a[j] <= a[i] )
            {
                if( dp[i] < dp[j] + 1 )
                {
                    dp[i] = dp[j] + 1;
                    from[i] = j;
                }
            }
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( dp[i] > ans )
        {
            ans = dp[i];
            end = i;
        }
    }

    cout << ans << '\n';
    vector<int> vec;

    while( end != -1 ) 
    {
        vec.push_back( a[end] );
        end = from[end];
    }

    for( int i = vec.size( ) - 1; i >= 0; -- i )
    {
        cout << vec[i];
        if( i != 0 ) cout << " ";
    }

    cout << '\n';
    return 0;
}