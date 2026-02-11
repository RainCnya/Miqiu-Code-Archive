#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const int maxlg = 20;

vector<int> adj[maxn];
int up[maxn][maxlg];
int dep[maxn];
int SG[maxn], SH[maxn];
char col[maxn];
int n, m;
string s;

void dfs( int u, int p )
{
    SG[u] = SG[p] + ( col[u] == 'G' );
    SH[u] = SH[p] + ( col[u] == 'H' );
    dep[u] = dep[p] + 1;
    up[u][0] = p;
    
    for( int i = 1; i < maxlg; ++ i ) up[u][i] = up[up[u][i - 1]][i - 1];   
    for( auto v : adj[u] ) if( v != p ) dfs( v, u );
}

int get_lca( int u, int v )
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = maxlg - 1; i >= 0; -- i ) if( ( diff >> i ) & 1 ) u = up[u][i];
    if( u == v ) return u;
    for( int i = maxlg - 1; i >= 0; -- i ) if( up[u][i] != up[v][i] ) u = up[u][i], v = up[v][i];
    return up[u][0];
}

void solve( )
{
    cin >> n >> m;
    cin >> s;
    for( int i = 1; i <= n; ++ i ) col[i] = s[i - 1];

    for( int i = 1; i <= n - 1; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs( 1, 0 );

    for( int i = 1; i <= m; ++ i )
    {
        int u, v; char c;
        cin >> u >> v >> c;
        int lca = get_lca( u, v );

        int cnt = 0;
        if( c == 'G' ) cnt = ( SG[u] + SG[v] - 2 * SG[lca] ) + ( col[lca] == 'G' );
        else cnt = ( SH[u] + SH[v] - 2 * SH[lca] ) + ( col[lca] == 'H' );

        if( cnt > 0 ) cout << "1";
        else cout << "0";
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}