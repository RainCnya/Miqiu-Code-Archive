#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

vector< int > adj[maxn];
ll a[maxn], sz_sum[maxn], f[maxn], dp[maxn];
int dep[maxn], mx1[maxn], mx2[maxn], son[maxn];
int n;

void dfs( int u, int p )
{
    sz_sum[u] = a[u];
    f[u] = 0;
    mx1[u] = dep[u];
    mx2[u] = 0;
    son[u] = 0;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dep[v] = dep[u] + 1;
        dfs( v, u );
        sz_sum[u] += sz_sum[v];
        f[u] += ( f[v] + sz_sum[v] );
        if( mx1[v] > mx1[u] )
        {
            mx2[u] = mx1[u];
            mx1[u] = mx1[v];
            son[u] = v;
        }
        else if( mx1[v] > mx2[u] )
        {
            mx2[u] = mx1[v];
        }
    }
}

void dfs2( int u, int p )
{
    ll sumdp = 0;
    ll sumf = 0;

    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs2( v, u );
        sumdp += dp[v] + sz_sum[v];
        sumf += f[v] + sz_sum[v];
    }

    dp[u] = max( f[u], sumdp );

    for( int v : adj[u] )
    {
        if( v == p ) continue;
        int depth = ( v == son[u] ) ? mx2[u] : mx1[u];
        ll cur = sumf + sz_sum[v] * ( depth - dep[v] + 1 );
        dp[u] = max( dp[u], cur );
    }
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
        adj[i].clear( );
    }

    for( int i = 1; i < n; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    dep[1] = 0;
    dfs( 1, 0 );
    dfs2( 1, 0 );

    for( int i = 1; i <= n; ++ i ) cout << dp[i] << ' ';
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