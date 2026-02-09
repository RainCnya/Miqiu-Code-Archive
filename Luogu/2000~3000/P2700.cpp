#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

struct Edge { 
    int u, v; ll w;
    bool operator < ( const Edge &oth ) const { return w > oth.w; }
} edges[maxn];
int edge_cnt;

bool is_enemy[maxn];
int fa[maxn];
ll mst_weight;
int n, k;

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    else return fa[x] = find( fa[x] );
}

void kruskal( )
{
    sort( edges + 1, edges + edge_cnt + 1 );

    for( int i = 1; i <= edge_cnt; ++ i )
    {
        auto [u, v, w] = edges[i];
        
        int fu = find( u ), fv = find( v );
        if( is_enemy[fu] && is_enemy[fv] ) continue;
        fa[fu] = fv;
        if( is_enemy[fu] ) is_enemy[fv] = 1;
        mst_weight += w;
    }
}

void solve( )
{
    cin >> n >> k;

    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    for( int i = 1; i <= k; ++ i )
    {
        int city;
        cin >> city;
        is_enemy[city] = 1;
    }

    ll sum = 0;
    for( int i = 1; i <= n - 1; ++ i ) 
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        edges[++ edge_cnt] = { u, v, w };
        sum += w;
    }

    kruskal( );
    cout << sum - mst_weight << endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}