#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 50;

vector<int> adj[maxn];
int dep[maxn];
int n, x;

void dfs( int u, int fa, int d )
{
    dep[u] = d;
    for( int v : adj[u] )
    {
        if( v == fa ) continue;
        dfs( v, u, d + 1 );
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x;

    for( int i = 1; i < n; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 1, 0, 0 );

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( x - dep[i] < 0 ) continue;
        int diff = x - dep[i];
        if( diff % 2 == 0 ) ans += i;
    }

    cout << ans << '\n';
    return 0;
}