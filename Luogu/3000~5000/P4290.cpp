#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 200 + 5;

bool ok[5][5][5];
int dp[maxn][maxn][5];
// dp[i][j][k] 表示 [i, j] 区间能否能转化为 k
int num[maxn];
int cnt[5];
string s;

char lst[5] = { ' ', 'W', 'I', 'N', 'G' };

int calc( char x )
{
    if( x == 'W' ) return 1;
    if( x == 'I' ) return 2;
    if( x == 'N' ) return 3;
    if( x == 'G' ) return 4;
    return 0;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for( int i = 1; i <= 4; ++ i ) cin >> cnt[i];

    for( int i = 1; i <= 4; ++ i )
    {
        while( cnt[i] -- )
        {
            char x, y; cin >> x >> y;
            ok[calc(x)][calc(y)][i] = 1;
        }
    }


    cin >> s;
    int n = s.length( );
    
    for( int i = 1; i <= n; ++ i ) 
    {
        num[i] = calc( s[i - 1] );
        dp[i][i][num[i]] = 1;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int i = 1; i + len - 1 <= n; ++ i )
        {
            int j = i + len - 1;
            for( int k = i; k < j; ++ k )
            {
                for( int a = 1; a <= 4; ++ a )
                {
                    if( !dp[i][k][a] ) continue;
                    for( int b = 1; b <= 4; ++ b )
                    {
                        if( !dp[k + 1][j][b] ) continue;
                        for( int c = 1; c <= 4; ++ c )
                        {
                            if( ok[a][b][c] && dp[i][k][a] && dp[k + 1][j][b] ) 
                                dp[i][j][c] = 1;
                        }
                    }
                }
            }
        }
    }

    bool found = 0;
    for( int k = 1; k <= 4; ++ k )
    {
        if( dp[1][n][k] )
        {
            cout << lst[k];
            found = 1;
        }
    }
    if( !found ) cout << "The name is wrong!";
    return 0;
}