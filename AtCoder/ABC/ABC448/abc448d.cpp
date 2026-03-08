#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

vector< int > adj[maxn];
ll a[maxn];
bool ans[maxn];
int n;

map< ll, int > cnt;

void dfs( int u, int p, bool flag )
{
    bool cur = ( flag || ( cnt[a[u]] > 0 ) );
    ans[u] = cur;
    cnt[a[u]] += 1;
    for( int v : adj[u] )
    {
        if( v == p ) continue;
        dfs( v, u, cur );
    }
    cnt[a[u]] -= 1;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    cnt.clear( );

    dfs( 1, 0, 0 );

    for( int i = 1; i <= n; ++ i )
    {
        if( ans[i] ) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}