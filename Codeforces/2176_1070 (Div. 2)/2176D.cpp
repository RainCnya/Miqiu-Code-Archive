#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using ll = long long;

const int maxn = 2e5 + 5;
const int mod = 998244353;

ll a[maxn];
map< ll, vector<int> > radj[maxn];
//vector< int > radj[maxn];
map< ll, int > memo[maxn];
int n, m;

vector< PII > edges;

int dfs( int u, ll diff )
{
    if( diff <= 0 ) return 0;
    if( memo[u].count( diff ) ) return memo[u][diff];
    
    ll cnt = 0;
    if( radj[u].count( diff ) )
    {
        for( int w : radj[u][diff] )
        {
            cnt = ( cnt + 1 ) % mod;
            ll _diff = a[u] - diff;
            cnt = ( cnt + dfs( w, _diff ) ) % mod;
        }
    }
    
    return memo[u][diff] = cnt;
}



void solve( )
{  
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )
    {
        radj[i].clear( );
        memo[i].clear( );
    }
    edges.clear( );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({ u, v });
        radj[v][a[u]].push_back( u );
    }

    ll ans = 0;

    for( auto& [u, v] : edges )
    {
        ans = ( ans + 1 ) % mod;
        ll need = a[v] - a[u];
        ans = ( ans + dfs( u, need ) ) % mod;
    }

    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
