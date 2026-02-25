#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair< ll, int >;

const int maxn = 2e5 + 50;
vector< PII > adj[maxn];
bool vis[maxn];
int n, m, l;
ll s, t;

void dfs( int u, int step, ll sum )
{
    if( step == l )
    {
        if( s <= sum && sum <= t )
        {
            vis[u] = 1;
        }
        return ;
    }
    for( auto [cost, v] : adj[u] )
    {
        dfs( v, step + 1, sum + cost );
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> l >> s >> t;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v; ll c;
        cin >> u >> v >> c;
        adj[u].push_back({ c, v });
    }
    
    dfs( 1, 0, 0 );

    for( int i = 1; i <= n; ++ i )
    {
        if( vis[i] ) cout << i << " ";
    }

    return 0;
}