#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 300 + 50;

struct Edge { 
    int u, v; ll w;
    bool operator < ( const Edge &oth ) const { return w < oth.w; }
} edges[maxn * maxn];
int edge_cnt;

int fa[maxn];
ll ws[maxn];
ll mst_weight;
int n;

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    else return fa[x] = find( fa[x] );
}

void kruskal( )
{
    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    sort( edges + 1, edges + edge_cnt + 1 );

    for( int i = 1; i <= edge_cnt; ++ i )
    {
        auto [u, v, w] = edges[i];
        
        int fu = find( u ), fv = find( v );
        if( fu != fv )
        {
            fa[fu] = fv;
            mst_weight += w;
        }
    }
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        ll w;
        cin >> w;
        edges[++ edge_cnt] = { 0, i, w };
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            ll w;
            cin >> w;
            if( w == 0 ) continue;
            edges[++ edge_cnt] = { i, j, w };
        }
    }

    kruskal( );
    cout << mst_weight << endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}