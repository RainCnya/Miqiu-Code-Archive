#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 2e3 + 5;

int f[maxn][maxn];
// f[i][j] 表示 A 前 i 个字符 完全转化为 B 前 j 个字符 的最少操作次数
string A, B;

int main( )
{
    cin >> A >> B;

    int lenA = A.length( ), lenB = B.length( );

    for( int i = 1; i <= lenA; ++ i ) f[i][0] = i;
    for( int j = 1; j <= lenB; ++ j ) f[0][j] = j;

    for( int i = 1; i <= lenA; ++ i )
    {
        for( int j = 1; j <= lenB; ++ j )
        {
            f[i][j] = min( f[i - 1][j] , f[i][j - 1] ) + 1;
            f[i][j] = min( f[i][j], f[i - 1][j - 1] + ( A[i-1] != B[j-1] ) );
        }
    }
    
    cout << f[lenA][lenB] << '\n';
    return 0;
}