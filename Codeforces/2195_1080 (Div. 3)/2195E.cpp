#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;

struct Node { int l, r; } tr[maxn];
ll dp[maxn], ans[maxn];
int n;

void dfs1( int u )
{
    if( u == 0 ) return ;
    if( tr[u].l == 0 )
    {
        dp[u] = 1;
        return ;
    }
    dfs1( tr[u].l );
    dfs1( tr[u].r );
    dp[u] = ( dp[tr[u].l] + dp[tr[u].r] + 3 ) % mod;
}

void dfs2( int u, ll sum )
{
    if( u == 0 ) return ;
    ans[u] = ( dp[u] + sum ) % mod;
    if( tr[u].l == 0 ) return ;
    dfs2( tr[u].l, ans[u] );
    dfs2( tr[u].r, ans[u] );
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        tr[i].l = tr[i].r = 0;
        dp[i] = ans[i] = 0;
    }

    for( int i = 1; i <= n; ++ i ) cin >> tr[i].l >> tr[i].r;

    dfs1( 1 );
    dfs2( 1, 0 );

    for( int i = 1; i <= n; ++ i ) cout << ans[i] << " ";
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}