#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 50;
const int maxp = 2000 + 50;
const long long linf = 1e18;

int T, MaxP, W;
int ap[maxn], bp[maxn];
int as[maxn], bs[maxn];
long long dp[maxp][maxp];

int main( )
{	
    cin >> T >> MaxP >> W;
    for( int i = 1; i <= T; ++ i )
    {
        cin >> ap[i] >> bp[i];
        cin >> as[i] >> bs[i];
    }

    memset( dp, 128, sizeof( dp ) );
    for( int i = 0; i <= T; ++ i )
        dp[i][0] = 0;
    
    for( int i = 1; i <= T; ++ i )
    {
        for( int j = 0; j <= as[i]; ++ j )
            dp[i][j] = -1 * ap[i] * j;
        
        for( int j = 0; j <= MaxP; ++ j )
            dp[i][j] = max( dp[i][j], dp[i-1][j] );
        
        int from = i - W - 1;
        if( from < 0 ) continue;

        deque<int> q1;
        for( int j = 0; j <= MaxP; ++ j )
        {
            while( !q1.empty( ) && q1.front( ) < j - as[i] )
                q1.pop_front( );
            
            while( !q1.empty( ) && 
                dp[from][ q1.back( ) ] + q1.back( ) * ap[i] <= 
                dp[from][j] + j * ap[i] )
                q1.pop_back( );
            q1.push_back( j );

            if( !q1.empty( ) )
                dp[i][j] = max( dp[i][j], dp[from][ q1.front( ) ] + (q1.front( ) - j) * ap[i] );
        }

        deque<int> q2;
        for( int j = MaxP; j >= 0; -- j )
        {
            while( !q2.empty( ) && q2.front( ) > j + bs[i] )
                q2.pop_front( );

            while( !q2.empty( ) && 
                dp[from][ q2.back( ) ] + q2.back( ) * bp[i] <= 
                dp[from][j] + j * bp[i] )
                q2.pop_back( );
            q2.push_back( j );

            if( !q2.empty( ) )
                dp[i][j] = max( dp[i][j], dp[from][ q2.front( ) ] + (q2.front( ) - j) * bp[i] );
        }
    }

    long long ans = 0;
    for( int i = 0; i <= MaxP; ++ i )
        ans = max( ans, dp[T][i] );
    
    cout << ans << '\n';
    return 0;
}