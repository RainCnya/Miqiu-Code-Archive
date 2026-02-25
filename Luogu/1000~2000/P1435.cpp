#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

string s;
int f[maxn][maxn];
// f[i][j] 表示 s[i...j] 最少需要几次操作才能变成回文串

int main( )
{
    cin >> s;
    int len = s.length( );
    s = ' ' + s;

    for( int i = 1; i <= len; ++ i ) f[i][i] = 0;
    for( int i = 2; i <= len; ++ i ) 
    {
        if( s[i] == s[i-1] ) f[i][i-1] = 0;
        else f[i][i-1] = 1;
    }

    for( int k = 2; k <= len; ++ k )
    {
        for( int i = 1; i + k - 1 <= len; ++ i )
        {
            int j = i + k - 1;
            f[i][j] = min( f[i+1][j], f[i][j-1] ) + 1;
            if( s[i] == s[j] ) f[i][j] = min( f[i][j], f[i+1][j-1] );
        }
    }

    cout << f[1][len] << '\n';
    return 0;
}