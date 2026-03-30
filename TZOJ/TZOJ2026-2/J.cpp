#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

struct Edge {
    int u, v; ll w;
    bool operator < ( const Edge &a ) const { return w < a.w; }
};

vector< Edge > edges;
int fa[maxn];
int n, m, r;

int find( int x ) { return fa[x] == x ? x : fa[x] = find( fa[x] ); }
void merge( int x, int y ) { fa[find( x )] = find( y ); }

void solve( )
{
    cin >> n >> m >> r;

    for( int i = 1; i <= n; ++ i ) fa[i] = i;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v; cin >> u >> v;
        merge( u, v );
    }

    for( int i = 1; i <= r; ++ i )
    {
        int u, v; ll w; 
        cin >> u >> v >> w;
        edges.push_back({ u, v, w });
    }

    sort( edges.begin( ), edges.end( ) );

    ll ans = 0;
    for( auto [u, v, w] : edges )
    {
        if( find( u ) != find( v ) )
        {
            ans += w;
            merge( u, v );
        }
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}