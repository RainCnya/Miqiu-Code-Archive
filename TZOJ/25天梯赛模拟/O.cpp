#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 50;
const int maxlg = 12;
const ll inf = 1e18;

ll dp[maxn][maxn];
ll h[maxn], d[maxn];
ll sum[maxn], st[maxn][maxlg];
int lg2[maxn];
int n, K;

void init_ST( )
{
    lg2[1] = 0;
    for( int i = 2; i < maxn; ++ i ) lg2[i] = lg2[i >> 1] + 1;
    for( int i = 1; i < maxn; ++ i ) st[i][0] = h[i];
    for( int j = 1; j < maxlg; ++ j )
    {
        for( int i = 1; i + ( 1 << j ) - 1 < maxn; ++ i )
            st[i][j] = max( st[i][j - 1], st[i + ( 1 << (j - 1) )][j - 1] );
    }
}

ll query( int l, int r )
{
    int k = lg2[r - l + 1];
    return max( st[l][k], st[r - (1 << k) + 1][k] );
}

void solve( )
{
    cin >> n >> K;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> d[i] >> h[i];
        sum[i] = sum[i - 1] + d[i];
    }

    init_ST( );

    for( int i = 0; i <= K; ++ i )
    {
        for( int j = 0; j <= n; ++ j )
        {
            dp[i][j] = inf;
        }
    }

    for( int j = 1; j <= n; ++ j )
    {
        dp[1][j] = sum[j] * query( 1, j );
    }

    for( int i = 2; i <= K; ++ i )
    {
        for( int j = i; j <= n; ++ j )
        {
            for( int k = i - 1; k < j; ++ k )
            {
                ll cost = dp[i - 1][k] + ( sum[j] - sum[k] ) * query( k + 1, j );
                dp[i][j] = min( dp[i][j], cost );
            }
        }
    }
    
    cout << dp[K][n] << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}