#include<bits/stdc++.h>
using namespace std;

const int maxn = 50;

long long dp[maxn][maxn];
long long a[maxn];
int root[maxn][maxn];
int n;
bool flag = 0;
vector<int> res;

void init( int l, int r )
{
    if( l > r ) return;
    if( l == r ) 
    {
        res.push_back( l );
        return;
    }
    int k = root[l][r];
    res.push_back( k );
    init( l, k - 1 );
    init( k + 1, r );
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    for( int i = 0; i <= n + 1; ++ i )
    {
        for( int j = 0; j <= n + 1; ++ j )
        {
            dp[i][j] = 0;
        }
        dp[i][i-1] = 1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        dp[i][i] = a[i];
        root[i][i] = i;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int l = 1; l + len - 1 <= n; ++ l )
        {
            int r = l + len - 1;
            for( int k = l; k <= r; ++ k )
            {
                long long cur = dp[l][k-1] * dp[k+1][r] + a[k];
                if( cur > dp[l][r] )
                {
                    dp[l][r] = cur;
                    root[l][r] = k;
                }
            }
        }
    }

    cout << dp[1][n] << '\n';
    init( 1, n );

    for( int i = 0; i < n; ++ i )
    {
        cout << res[i];
        if( i != n - 1 ) cout << " ";
    }
    return 0;
}