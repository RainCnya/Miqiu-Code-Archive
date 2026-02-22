#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e3 + 50;
const int mod = 80112002;

vector< int > adj[maxn];
int indeg[maxn], outdeg[maxn];
int memo[maxn];
int n, m, ans;

int dfs( int u )
{
    if( memo[u] != 0 ) return memo[u];
    int res = 0;
    for( int v : adj[u] )
    {
        res = ( res + dfs( v ) ) % mod;     
    }
    return memo[u] = res;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back( u );
        indeg[v] ++, outdeg[u] ++;
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( indeg[i] == 0 ) memo[i] = 1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        dfs( i );
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( outdeg[i] == 0 ) ans = ( ans + memo[i] ) % mod;
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}