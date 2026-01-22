#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 50;
const int maxm = 1e4 + 50;

struct Edge {
    int u, v, w;
    bool operator <( const Edge &other ) const {
        return w < other.w;
    }
} edges[maxm];

int fa[maxn];
int n, m, k;
ll mst_weight;

int find( int x )
{
    if( x == fa[x] ) return fa[x];
    else return fa[x] = find( fa[x] );
}

bool kruskal( )
{
    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    sort( edges + 1, edges + m + 1 );

    if( n == k ) return 1;

    int cnt = 0;
    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, w] = edges[i];
        int ru = find( u ), rv = find( v );

        if( ru != rv )
        {
            fa[ru] = rv;
            mst_weight += w;
            cnt ++;
            if( cnt == n - k ) break;
        }
    }
    return cnt == n - k;
}

int main( )
{
    cin >> n >> m >> k;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    if( kruskal( ) ) cout << mst_weight << '\n'; 
    else cout << "No Answer" << '\n';
    return 0;
}