#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;
const ll inf = 1e18;

vector< int > adj[maxn], radj[maxn];
ll minp[maxn], maxp[maxn], val[maxn];
int n, m;

struct State {
    ll d; int u;
    bool operator < ( const State& oth ) const { return d > oth.d; }
};

void spfa_min( )
{
    for( int i = 1; i <= n; ++ i ) minp[i] = inf;
    queue< int > q;
    q.push( 1 );
    minp[1] = val[1];

    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );

        for( int v : adj[u] )
        {
            if( minp[v] > min( minp[u], val[v] ) )
            {
                minp[v] = min( minp[u], val[v] );
                q.push( v );
            }
        }
    }
}

void spfa_max( )
{
    for( int i = 1; i <= n; ++ i ) maxp[i] = -inf;
    queue< int > q;
    q.push( n );
    maxp[n] = val[n];

    while( !q.empty( ) )
    {
        int u = q.front( ); q.pop( );

        for( int v : radj[u] )
        {
            if( maxp[v] < max( maxp[u], val[v] ) )
            {
                maxp[v] = max( maxp[u], val[v] );
                q.push( v );
            }
        }
    }
}


void solve( )
{
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i ) cin >> val[i];

    for( int i = 1; i <= m; ++ i )
    {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back( y );
        radj[y].push_back( x );
        if( z == 2 ) adj[y].push_back( x );
        if( z == 2 ) radj[x].push_back( y );
    }

    spfa_min( );
    spfa_max( );

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans = max( ans, maxp[i] - minp[i] );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}