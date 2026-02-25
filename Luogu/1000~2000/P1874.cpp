#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int maxs = 40 + 5;
const int inf = 0x3f3f3f3f;

int f[maxs][maxn];
int num[maxs][maxs];
// f[i][k] 表示 使用 S 的前 i 个字符，总和为 k 的最小操作次数
string s;
int n;

int calc( int l, int r )
{
    int res = 0;
    for( int i = l; i <= r; ++ i ) 
    {
        res = res * 10 + s[i] - '0';
        if( res > n ) return inf;
    }
    return res;
}

int main( )
{
    cin >> s >> n;

    int len = s.length( );
    s = ' ' + s;

    memset( f, 0x3f, sizeof( f ) );
    f[0][0] = 0;

    for( int i = 1; i <= len; ++ i )
    {
        for( int j = 0; j < i; ++ j )
        {
            int val = calc( j + 1, i );
            if( val > n ) continue;

            for( int k = val; k <= n; ++ k )
            {
                if( f[j][k - val] == inf ) continue;
                f[i][k] = min( f[i][k], f[j][k - val] + 1 );
            }
        }
    }

    int ans = f[len][n];
    if( ans > len ) cout << -1 << '\n';
    else cout << ans - 1 << '\n';

    return 0;
}