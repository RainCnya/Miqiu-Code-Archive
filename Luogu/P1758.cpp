#include<bits/stdc++.h>
using namespace std;

const int mod = 1024523;
const int maxn = 500 + 50;

int dp[2][maxn][maxn];
int cur, nxt;
int m, n;
string s1, s2;

void add( int a, int b, int val )
{
    dp[nxt][a][b] = ( dp[nxt][a][b] + val ) % mod;
}

int main()
{	
    cin >> n >> m;
    cin >> s1 >> s2;

    s1 = ' ' + s1;
    s2 = ' ' + s2;

    dp[0][0][0] = 1;

    for( int k = 0; k < n + m; ++ k )
    {
        cur = ( k & 1 );
        nxt = ( k + 1 ) & 1;
        memset( dp[nxt], 0, sizeof( dp[nxt] ) );

        int l = max( 0 , k - m );
        int r = min( n , k );

        for( int i = l; i <= r; ++ i )
        {
            for( int j = l; j <= r; ++ j )
            {
                if( !dp[cur][i][j] ) continue;
                int _i = k - i, _j = k - j;
                int val = dp[cur][i][j];

                if( i < n && j < n && s1[i+1] == s1[j+1] ) 
                    add( i+1, j+1, val );    
                if( i < n && _j < m && s1[i+1] == s2[_j+1] )
                    add( i+1, j, val );
                if( _i < m && j < n && s2[_i+1] == s1[j+1] )
                    add( i, j+1, val );
                if( _i < m && _j < m && s2[_i+1] == s2[_j+1] )
                    add( i, j, val );
                
            }
        }
    }

    cout << dp[(n + m) & 1][n][n] << '\n';

    return 0;
}