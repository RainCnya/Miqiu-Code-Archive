#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

struct Edge { int v, w; };
vector<Edge> adj[maxn];

int indeg[maxn], outdeg[maxn];
bool is_input[maxn];
int c[maxn], u[maxn];
int n, p;

void solve( )
{
    cin >> n >> p;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> c[i] >> u[i];
        if( c[i] > 0 ) is_input[i] = 1;
    }

    for( int i = 1; i <= p; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back( {v, w} );
        indeg[v] ++;
        outdeg[u] ++;
    }

    queue< int > q;
    for( int i = 1; i <= n; ++ i )
    {
        if( indeg[i] == 0 ) q.push( i );
        else c[i] -= u[i];
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );

        if( c[u] > 0 )
        {
            for( auto [v, w] : adj[u] )
            {
                c[v] += c[u] * w;
            }
        }

        for( auto [v, w] : adj[u] )
        {
            indeg[v] --;
            if( indeg[v] == 0 ) q.push( v );
        }
    }


    bool exist = 0;
    vector< pair< int, int > > res;
    for( int i = 1; i <= n; ++ i )
    {
        if( outdeg[i] == 0 && c[i] > 0 )
        {
            res.push_back({ i, c[i] });
            exist = 1;
        }
    }

    if( !exist )
    {
        cout << "NULL" << '\n';
        return ;
    }
    sort( res.begin( ), res.end( ) );
    for( auto [i, j] : res )
    {
        cout << i << ' ' << j << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}