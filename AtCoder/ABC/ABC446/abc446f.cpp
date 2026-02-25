#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;
const int inf = 0x3f3f3f3f;

vector< int > adj[maxn];
int f[maxn];
int dif[maxn];
int n, m;

struct State {
    int u, d;
    bool operator < ( const State &oth ) const { return d > oth.d; }
};

void dijkstra( )
{    
    for( int i = 1; i <= n; ++ i ) f[i] = inf;

    priority_queue< State > pq;
    pq.push({ 1, 1 });
    f[1] = 1;

    while( !pq.empty( ) )
    {
        auto [u, d] = pq.top( ); pq.pop( );
        if( d > f[u] ) continue;
        
        for( int v : adj[u] )
        {
            int nf = max( d, u );
            if( nf < f[v] )
            {
                f[v] = nf;
                pq.push({ v, f[v] });
            }
        }
    }
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v; cin >> u >> v;
        adj[u].push_back( v );
    }

    dijkstra( );

    for( int i = 1; i <= n; ++ i )
    {
        if( f[i] < i && f[i] != inf )
        {
            dif[f[i]] ++;
            dif[i] --;
        }
    }

    int sum = 0;
    int max_f = 0;
    for( int k = 1; k <= n; ++ k )
    {
        sum += dif[k];
        max_f = max( max_f, f[k] );
        if( max_f <= k ) cout << sum << '\n';
        else cout << -1 << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}