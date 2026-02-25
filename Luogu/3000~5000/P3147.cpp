#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 262144 + 5;

int f[maxn][60];
int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int ans = 0;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int val; cin >> val;
        f[i][val] = i;
        ans = max( ans, val );
    }

    for( int k = 1; k < 60; ++ k )
    {
        for( int i = 1; i <= n; ++ i )
        {
            if( f[i][k] == 0 ) continue;

            if( f[i][k] && f[f[i][k] + 1][k] )
            {
                f[i][k + 1] = f[f[i][k] + 1][k];
                ans = max( ans, k + 1 );
            }
        }
    }

    cout << ans << '\n';
    return 0;
}