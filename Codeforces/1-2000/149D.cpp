#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
const int mod = 1000000007;

string s;
int dp[maxn][maxn][3][3];
int p[maxn];
int n;

bool ok( int c1, int c2 )
{
    return !( c1 > 0 && c2 > 0 && c1 == c2 );
}

bool check( int cl, int cr )
{
    return ( cl > 0 ) ^ ( cr > 0 ); 
}

long long dfs( int l, int r, int cl, int cr )
{
    if( dp[l][r][cl][cr] != -1 ) return dp[l][r][cl][cr];

    long long ans = 0;

    if( l + 1 == r )
    {
        return dp[l][r][cl][cr] = check( cl, cr );
    }

    if( p[l] == r )
    {
        if( !check( cl, cr ) ) return dp[l][r][cl][cr] = 0;
        for( int ncl = 0; ncl < 3; ++ ncl )
        {
            for( int ncr = 0; ncr < 3; ++ ncr )
            {
                if( !ok( cl, ncl ) || !ok( cr, ncr ) ) continue;
                ans = ( ans + dfs( l + 1, r - 1, ncl, ncr ) ) % mod;
            }
        }
    }
    else
    {
        int k = p[l];
        for( int mcl = 0; mcl < 3; ++ mcl )
        {
            for( int mcr = 0; mcr < 3; ++ mcr )
            {
                if( !ok( mcl, mcr ) ) continue;
                long long lres = dfs( l, k, cl, mcl );
                long long rres = dfs( k+1, r, mcr, cr );
                if( lres && rres )
                {
                    ans = ( ans + lres * rres ) % mod;
                }
            }
        }
    }

    return dp[l][r][cl][cr] = ans;
}

int main()
{	
    cin >> s;
    n = s.length( );
    s = ' ' + s;

    stack<int> stk;
    for( int i = 1; i <= n; ++ i )
    {
        if( s[i] == '(' ) stk.push( i );
        else if( !stk.empty( ) )
        {
            p[stk.top( )] = i;
            p[i] = stk.top( );
            stk.pop( );
        }
    }

    memset( dp, -1, sizeof( dp ) );

    long long ans = 0;
    for( int i = 0; i < 3; ++ i )
    {
        for( int j = 0; j < 3; ++ j )
        {
            ans = ( ans + dfs( 1, n, i, j ) ) % mod;
        }
    }

    cout << ans << '\n';
    return 0;
}