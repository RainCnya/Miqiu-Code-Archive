#include<bits/stdc++.h>
using namespace std;

const int maxn = 4000 + 50;

int n, m, k, t;
long long dp[maxn][maxn];
deque<int> q;

void insert( int k, int pos )
{
    while( !q.empty( ) && dp[k][pos] > dp[k][ q.back( ) ] )
        q.pop_back( );
    q.push_back( pos );
}

int find( int k, int pos )
{
    if( pos + t <= m )
        insert( k, pos + t );
    while( q.front( ) + t < pos )
        q.pop_front( );
    return q.front( );
}

int main()
{	
    cin >> n >> m >> k >> t;
    while( k -- )
    {
        int x, y, v;
        cin >> x >> y >> v;
        dp[x][y] = v;
    }
    for( int i = 2; i <= n; ++ i )
    {
        for( int j = 1; j <= t; ++ j )
        {
            insert( i - 1, j );
        }
        for( int j = 1; j <= m; ++ j )
        {
            dp[i][j] += dp[i-1][ find( i - 1, j ) ];
        }
        q.clear( );
    }
    long long ans = 0;
    for( int i = 1; i <= m; ++ i )
    {
        ans = max( ans, dp[n][i] );
    }
    cout << ans << '\n';
    return 0;
}