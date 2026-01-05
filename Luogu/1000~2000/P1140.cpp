#include<bits/stdc++.h>
using namespace std;

const int tab[5][5] = 
{
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}
};
const int maxn = 100 + 5;

int a[maxn], b[maxn];
int dp[maxn][maxn];
int l1, l2;
string s1, s2;

int calc( char x )
{
    if( x == 'A' ) return 0;
    if( x == 'C' ) return 1;
    if( x == 'G' ) return 2;
    if( x == 'T' ) return 3;
}

int main()
{	
    cin >> l1 >> s1;
    cin >> l2 >> s2;

    for( int i = 1; i <= l1; ++ i )
    {
        int x = calc( s1[i - 1] );
        a[i] = x;
    }
    for( int i = 1; i <= l2; ++ i )
    {
        int x = calc( s2[i - 1] );
        b[i] = x;
    }
    
    for( int i = 1; i <= l1; ++ i )
    {
        for( int j = 1; j <= l2; ++ j )
        {
            dp[i][j] = -1e9;
        }
    }

    for( int i = 1; i <= l1; ++ i )
    {
        dp[i][0] = dp[i - 1][0] + tab[a[i]][4];
    }
    for( int i = 1; i <= l2; ++ i )
    {
        dp[0][i] = dp[0][i - 1] + tab[b[i]][4];
    }

    for( int i = 1; i <= l1; ++ i )
    {
        for( int j = 1; j <= l2; ++ j )
        {
            dp[i][j] = max( dp[i][j], dp[i][j-1] + tab[ b[j] ][4] );
            dp[i][j] = max( dp[i][j], dp[i-1][j] + tab[ a[i] ][4] );
            dp[i][j] = max( dp[i][j], dp[i-1][j-1] + tab[ a[i] ][ b[j] ] );
        }
    }

    cout << dp[l1][l2] << '\n';
    return 0;
}