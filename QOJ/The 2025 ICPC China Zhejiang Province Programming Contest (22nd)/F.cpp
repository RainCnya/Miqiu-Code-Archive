#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int maxc = 50 + 5;
const int inf = 1e9;

struct Node { int u, d, s; };

vector< int > adj[maxn];
vector< int > nodes[maxc];
int col[maxn];

int d1[maxn], d2[maxn];
int s1[maxn], s2[maxn];
vector< int > vis;

int n, m, k;

bool update( int v, int d, int s, queue< Node > &q )
{
    if( s == s1[v] )
    {
        if( d < d1[v] ) 
        {
            d1[v] = d;
            return 1;
        }
    }
    else 
    {
        if( d < d1[v] )
        {
            d2[v] = d1[v], s2[v] = s1[v];
            d1[v] = d, s1[v] = s;
            if( s2[v] == 0 ) vis.push_back( v );
            return 1;
        }
        else if( d < d2[v] )
        {
            d2[v] = d, s2[v] = s;
            return 1;
        }
    }
    return 0;
}

bool check_bfs( int c, int k )
{
    if( nodes[c].size( ) < 2 ) return 1;

    queue< Node > q;
    vis.clear( );

    for( int u : nodes[c] )
    {
        d1[u] = 0, s1[u] = u;
        q.push({ u, 0, u });
        vis.push_back( u );
    }

    while( !q.empty( ) )
    {
        auto [u, d, s] = q.front( ); q.pop( );

        if( d >= k - 1 ) continue;

        for( int v : adj[u] )
        {
            if( col[v] == c && v != s ) return 0;
            if( update( v, d + 1, s, q ) ) q.push({ v, d + 1, s });
        }
    }
    return 1;
}

void solve( )
{
    cin >> n >> m >> k;

    for( int i = 1; i <= 50; ++ i ) nodes[i].clear( );
    for( int i = 1; i <= n; ++ i )
    {
        adj[i].clear( );
        d1[i] = d2[i] = inf;
        s1[i] = s2[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> col[i];
        nodes[col[i]].push_back(i);
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
    }

    if( k == 1 )
    {
        cout << "YES" << '\n';
        return ;
    }

    bool ok = 1;
    for( int c = 1; c <= 50; ++ c )
    {
        for( int node : vis ) 
        {
            d1[node] = inf;
            s1[node] = 0;
        }
        if( !check_bfs( c, k ) )
        {
            ok = 0;
            break;
        }
    }

    if( ok ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}