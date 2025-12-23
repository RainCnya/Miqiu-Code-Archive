#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;
const int inf = 0x3f3f3f3f;

int n, l, r;

int a[maxn];
int dp[maxn];
int ans = -inf;

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> l >> r;

    for( int i = 0; i <= n; ++ i )
    {
        cin >> a[i];
        dp[i] = -inf;
    }

    dp[0] = a[0];
    deque<int> q;
    q.push_back( 0 );

    for( int i = l; i <= n; ++ i )
    {
        while( !q.empty( ) && dp[ q.back( ) ] <= dp[i - l] )
            q.pop_back( );
        q.push_back( i - l );

        while( !q.empty( ) && q.front( ) < i - r )
            q.pop_front( );
        
        dp[i] = dp[ q.front( ) ] + a[i];
        
        if( i + r > n ) 
            ans = max( ans, dp[i] );        
    }

    cout << ans << '\n';
    return 0;
}