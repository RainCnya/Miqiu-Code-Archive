#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int n, k;
long long a[maxn];
long long sum[maxn];
long long dp[maxn][2];

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    
    deque<int> q;
    q.push_back( 0 );
    for( int i = 1; i <= n; ++ i )
    {
        while( !q.empty( ) && q.front( ) < i - k )
            q.pop_front( );
        
        long long pmx = dp[ q.front( ) ][0] - sum[ q.front( ) ];
        dp[i][1] = sum[i] + pmx;
        dp[i][0] = max( dp[i-1][0], dp[i-1][1] );
        
        long long pi = dp[i][0] - sum[i];
        while( !q.empty( ) && (dp[q.back( )][0] - sum[q.back( )]) <= pi )
            q.pop_back( );
        
        q.push_back( i );
    }

    cout << max( dp[n][0], dp[n][1] ) << '\n';
    return 0;
}