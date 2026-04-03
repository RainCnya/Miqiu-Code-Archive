#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;

struct Edge {
    int u, v; ll w;
    friend bool operator < ( const Edge &a, const Edge &b ) { return a.w < b.w; }
};

vector< Edge > edges;

ll mat[maxn][maxn];
ll dist[maxn];
int fa[maxn];

struct Edge2 { int v; ll w; };
vector< Edge2 > adj[maxn];
int n;

int find( int x ) { 
    if( fa[x] == x ) return x;
    return fa[x] = find( fa[x] ); 
}

void merge( int x, int y ) { 
    int rx = find( x ), ry = find( y );
    if( rx != ry ) fa[rx] = ry;
}

void fail( ) { cout << "No" << '\n'; return; }

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = i + 1; j <= n; ++ j )
        {
            int dis; cin >> dis;
            mat[i][j] = mat[j][i] = dis;
            edges.push_back({ i, j, dis });
        }
    }

    sort( edges.begin( ), edges.end( ) );
    for( int i = 1; i <= n; ++ i ) fa[i] = i;

    int cnt = 0;
    for( auto &[u, v, w] : edges )
    {
        if( find( u ) != find( v ) )
        {
            adj[u].push_back( { v, w } );
            adj[v].push_back( { u, w } );
            cnt ++;
            merge( u, v );
        }
    }

    if( cnt != n - 1 ) return fail( );

    for( int i = 1; i <= n; ++i )
    {
        memset( dist, -1, sizeof( dist ) );
        queue< int > q;
        q.push( i );
        dist[i] = 0;
        while( !q.empty( ) )
        {
            int u = q.front( );
            q.pop( );
            for( auto &[v, w] : adj[u] )
            {
                if( dist[v] == -1 )
                {
                    dist[v] = dist[u] + w;
                    if( dist[v] != mat[i][v] ) return fail( );
                    q.push( v );
                }
            }
        }
    }

    cout << "Yes" << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}