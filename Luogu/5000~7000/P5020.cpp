#include<bits/stdc++.h>
using namespace std;

const int maxdp = 25000 + 50;
const int maxn = 100 + 5;

int dp[maxdp];
int a[maxn];
int n;

int main( )
{	
    int T;
    cin >> T;
    while( T -- )
    {
        memset( dp, 0, sizeof( dp ) );
        cin >> n;
        int ans = n;

        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i];
        }
        sort( a + 1, a + n + 1 );
        
        dp[0] = 1;
        for( int i = 1; i <= n; ++ i )
        {
            if( dp[ a[i] ] )
            {
                ans --;
                continue;
            }
            for( int j = a[i]; j <= a[n]; ++ j )
            {
                dp[j] = dp[j] | dp[ j - a[i] ];
            }
        }
        
        cout << ans << '\n';
    }    
    return 0;
}