#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 5;
const int maxm = 2e3 + 5;

bitset< maxn > a[maxm];
int n, m;
// 1 唯一解 | 0 无穷解
int gauss( int n, int m )
{
    int ans = 0;
    int curi = 1;
    for( int i = 1; i <= n; ++ i )
    {
        int pivot = curi;
        while( pivot <= m && a[pivot][i] == 0 ) pivot ++;
        
        if( pivot > m ) return 0;

        ans = max( ans, pivot );

        swap( a[pivot], a[curi] );

        for( int r = 1; r <= m; ++ r )
        {
            if( r != curi && a[r][i] ) a[r] ^= a[curi];
        }
        curi ++;
    }
    return ans;
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );

    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        string s; int res;
        cin >> s >> res;
        for( int j = 1; j <= n; ++ j )
            if( s[j - 1] == '1' ) a[i][j] = 1;
        a[i][n + 1] = res;
    }

    int ans = gauss( n, m );
    if( ans == 0 ) 
    {
        cout << "Cannot Determine" << "\n";
        return 0;
    }

    cout << ans << '\n';
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i][n + 1] ) cout << "?y7M#" << '\n';
        else cout << "Earth" << '\n';
    } 

    return 0;
}