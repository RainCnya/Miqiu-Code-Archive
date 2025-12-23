#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 50;
int dp[maxn][maxn];

int main( )
{	
    string s1, s2;
    cin >> s1 >> s2;
    int lenx = s1.length( );
    int leny = s2.length( );

    for( int i = 1; i <= lenx; ++ i )
    {
        for( int j = 1; j <= leny; ++ j )
        {
            if( s1[i - 1] == s2[j - 1] ) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
            }
        }
    }

    cout << dp[lenx][leny] << '\n'; 
    return 0;
}