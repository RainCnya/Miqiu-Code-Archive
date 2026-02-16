#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
const int maxlg = 20;

struct Node { int l, r, p; } tr[maxn];
ll dp1[maxn], dp2[maxn];
int up[maxn][maxlg];
int pos[maxn];
vector< int > order;
int n, q;

void dfs1( int u, int p )
{
    if( u == 0 ) return ;
    tr[u].p = p;
    if( tr[u].l == 0 )
    {
        dp1[u] = 1;
        return ;
    }
    dfs1( tr[u].l, u );
    dfs1( tr[u].r, u );
    dp1[u] = dp1[tr[u].l] + dp1[tr[u].r] + 3;
}

void dfs2( int u, ll sum )
{
    if( u == 0 ) return ;
    dp2[u] = dp1[u] + sum;
    
    up[u][0] = tr[u].p;
    for( int i = 1; i < maxlg; ++ i ) up[u][i] = up[ up[u][i - 1] ][i - 1];

    if( tr[u].l == 0 ) return ;
    dfs2( tr[u].l, dp2[u] );
    dfs2( tr[u].r, dp2[u] );
}

void dfs3( int u )
{
    pos[u] = order.size( ) - 1;
    if( tr[u].l == 0 ) 
    {
        order.push_back( tr[u].p );
        return ;
    }
    order.push_back( tr[u].l );
    dfs3( tr[u].l );
    order.push_back( tr[u].r );
    dfs3( tr[u].r );
    order.push_back( tr[u].p );
}

void solve( )
{
    cin >> n >> q;

    order.clear( );
    for( int i = 1; i <= n; ++ i )
    {
        tr[i].l = tr[i].r = 0;
        dp1[i] = dp2[i] = pos[i] = 0;
        for( int j = 0; j < maxlg; ++ j ) up[i][j] = 0;
    }

    for( int i = 1; i <= n; ++ i ) cin >> tr[i].l >> tr[i].r;

    dfs1( 1, 0 );
    dfs2( 1, 0 );
    order.push_back( 1 );
    dfs3( 1 );

    while( q -- )
    {
        ll v, k;
        cin >> v >> k;

        ll u = v;
        for( int i = maxlg - 1; i >= 0; -- i )
        {
            if( up[u][i] == 0 ) continue;
            if( dp2[v] - dp2[ up[u][i] ] <= k ) u = up[u][i];
        }
        ll rem = k - ( dp2[v] - dp2[u] );
        cout << order[ pos[u] + rem ] << " ";
    }
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