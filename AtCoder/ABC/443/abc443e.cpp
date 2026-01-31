#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e3 + 5;

int dp[maxn][maxn];
int limit[maxn];
string s[maxn];
int n, c;

void solve( )
{
    cin >> n >> c;

    for( int i = 1; i <= n; ++ i ) limit[i] = 0;

    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> s[i];
        s[i] = ' ' + s[i];
        for( int j = 1; j <= n; ++ j )
        {
            if( s[i][j] == '#' ) limit[j] = i;
            dp[i][j] = 0;
        }
    }

    dp[n][c] = 1;
    for( int i = n - 1; i >= 1; -- i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            if( dp[i + 1][j] == 1 ) dp[i][j] = 1;
            else if( dp[i + 1][j] == 2 && s[i][j] == '.' ) dp[i][j] = 2;

            if( j > 1 && dp[i + 1][j - 1] > 0 )
            {
                if( i >= limit[j] ) dp[i][j] = 1;
                else if( dp[i][j] == 0 && s[i][j] == '.' ) dp[i][j] = 2;
            }

            if( j < n && dp[i + 1][j + 1] > 0 )
            {
                if( i >= limit[j] ) dp[i][j] = 1;
                else if( dp[i][j] == 0 && s[i][j] == '.' ) dp[i][j] = 2;
            }
        }
    }

    for( int j = 1; j <= n; ++ j )
    {
        if( dp[1][j] > 0 ) cout << 1;
        else cout << 0;
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}