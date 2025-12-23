#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 50;
const long long inf = 1e18;

int n, m, p;
int v[maxn][maxn];
int w[maxn];
long long dp[maxn];
long long sum[maxn][maxn];

deque< pair<long long, int> > q[maxn];

int getpre( int u )
{
    return u == 1 ? n : u - 1;
}

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> p;
    for( int i = 1; i <= n; ++ i )
        for( int j = 1; j <= m; ++ j )
            cin >> v[i][j];

    for( int i = 1; i <= n; ++ i )
        cin >> w[i];

    memset( sum, 0, sizeof( sum ) );

    for( int j = 1; j <= m; ++ j )
    {
        for( int i = 1; i <= n; ++ i )
        {
            int prev = getpre( i );
            sum[i][j] = sum[prev][j-1] + v[prev][j];
        }
    }

    for( int j = 1; j <= m; ++ j )
        dp[j] = -inf;
    dp[0] = 0;

    for( int j = 1; j <= m; ++ j )
    {
        for( int i = 1; i <= n; ++ i )
        {
            int id = ( (i - j) % n + n ) % n;
            int pid = getpre( i );

            if( dp[j - 1] > -inf )
            {
                long long val = dp[j - 1] - sum[pid][j - 1] - w[pid];
                while( !q[id].empty( ) && q[id].back( ).first <= val )
                    q[id].pop_back( );
                q[id].push_back({ val, j - 1 });
            }

            while( !q[id].empty( ) && q[id].front( ).second < j - p )
                q[id].pop_front( );
            
            if( !q[id].empty( ) )
            {
                long long res = q[id].front( ).first + sum[i][j];
                dp[j] = max( dp[j], res );
            }
        }
    }

    cout << dp[m] << '\n';
    return 0;
}
