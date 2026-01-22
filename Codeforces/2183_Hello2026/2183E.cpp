#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxm = 3000 + 5;
const int mod = 998244353;

vector< int > divs[maxm];
int dp[2][maxm];
int a[maxm];
int n, m;


void init( )
{
    for( int i = 1; i < maxm; ++ i )
    {
        for( int j = i * 2; j < maxm; j += i )
        {
            divs[j].push_back(i);
        }
    }
}


void solve( )
{
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    if( a[1] > 1 )
    {
        cout << 0 << '\n';
        return;
    } 

    for( int j = 0; j <= m; ++ j )
    {
        dp[0][j] = dp[1][j] = 0;
    }

    dp[1][1] = 1;

    for( int i = 2; i <= n; ++ i )
    {
        int curr = i % 2;
        int prev = ( i - 1 ) % 2;

        for( int j = 0; j <= m; ++ j ) dp[curr][j] = 0;
        
        int st = i, ed = m;
        if( a[i] != 0 ) st = ed = a[i];

        for( int j = st; j <= ed; ++ j )
        {
            for( int d : divs[j] )
            {
                int p = j - d;
                if( dp[prev][p] == 0 ) continue;
                dp[curr][j] = ( dp[curr][j] + dp[prev][p] ) % mod;
            } 
        }
    }
    
    int ans = 0;
    int idx = n % 2;
    for( int j = 1; j <= m; ++ j )
    {
        ans = ( ans + dp[idx][j] ) % mod;
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init( );

    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}