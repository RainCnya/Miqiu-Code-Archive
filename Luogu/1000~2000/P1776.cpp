// 多重背包
#include<bits/stdc++.h>
using namespace std;

const int maxn = 4e4 + 50;

int dp[maxn];
int dp1[maxn];
int n, W;
int v, w, c;

int getVal( int x )
{
    return dp1[x] - ( x / w ) * v;
}

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> W;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> v >> w >> c;
        for( int j = 0; j <= W; ++ j )
        {
            dp1[j] = dp[j];
        }

        for( int r = 0; r < w; ++ r )
        {
            deque<int> q;
            for( int j = r; j <= W; j += w )
            {
                while( !q.empty( ) && q.front( ) < j - c * w )
                    q.pop_front( );
                
                while( !q.empty( ) && getVal( q.back( ) )  <= getVal( j ) )
                    q.pop_back( );
                q.push_back( j );

                dp[j] = dp1[ q.front( ) ] + ( j - q.front( ) ) / w * v;
            }
        }
    }

    cout << dp[W] << '\n';
    return 0;
}