#include<bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 50;
const int mod = 1e8;

long long dp[2][maxn];
long long cnt[2][maxn];
int t = 0;

int main( )
{	
    string a, b;
    cin >> a >> b;
    int lena = a.length( ) - 1;
    int lenb = b.length( ) - 1;

    for( int j = 0; j <= lenb; ++ j )
    {
        cnt[0][j] = 1;
    }
    cnt[1][0] = 1;
    
    int t = 0;
    for( int i = 1; i <= lena; ++ i, t ^= 1 )
    {
        cnt[t^1][0] = 1;
        for( int j = 1; j <= lenb; ++ j )
        {

            if( a[i-1] == b[j-1] ) {
                dp[t^1][j] = dp[t][j-1] + 1;
            } else {
                dp[t^1][j] = max( dp[t][j], dp[t^1][j-1] );
            }

            cnt[t^1][j] = 0;    

            if( a[i-1] == b[j-1] )
                cnt[t^1][j] = (cnt[t^1][j] + cnt[t][j-1]) % mod;
            if( dp[t^1][j] == dp[t][j] )
                cnt[t^1][j] = (cnt[t^1][j] + cnt[t][j]) % mod;
            if( dp[t^1][j] == dp[t^1][j-1] )
                cnt[t^1][j] = (cnt[t^1][j] + cnt[t^1][j-1]) % mod;
            if( a[i-1] != b[j-1] && dp[t^1][j] == dp[t][j-1] )
                cnt[t^1][j] = (cnt[t^1][j] - cnt[t][j-1] + mod) % mod;
        }
    }

    cout << dp[t][lenb] << "\n" << cnt[t][lenb] << '\n';
    return 0;
}