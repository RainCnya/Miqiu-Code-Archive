#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

vector< int > adj[maxn];
int indeg[maxn];
int n, m;

void solve( )
{
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i ) 
    {
        adj[i].clear( );
        indeg[i] = 0;
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[v].push_back( u );
        indeg[u] ++;
    }

    priority_queue< int > pq;
    for( int i = 1; i <= n; ++ i )
    {
        if( indeg[i] == 0 ) pq.push( i );
    }

    vector< int > ans;
    while( !pq.empty( ) )
    {
        int u = pq.top( );
        pq.pop( );
        ans.push_back( u );
        for( int v : adj[u] )
        {
            indeg[v] --;
            if( indeg[v] == 0 ) pq.push( v );
        }
    }

    if( ans.size( ) != n )
    {
        cout << "Impossible!" << '\n';
        return;
    }

    reverse( ans.begin( ), ans.end( ) );
    for( int u : ans ) cout << u << ' ';
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}