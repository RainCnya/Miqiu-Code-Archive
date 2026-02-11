#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

vector<int> adj[maxn];
int fa[maxn], dep[maxn], sz[maxn], son[maxn];
int top[maxn], dfn[maxn], rnk[maxn], timer;
int w[maxn];
int n, m, r, mod;

struct Node {
    int l, r;
    ll sum, add;
} tr[ maxn << 2 ];

#define ls u << 1
#define rs u << 1 | 1

void pushup( int u ) {
    tr[u].sum = ( tr[ls].sum + tr[rs].sum ) % mod;
}

void pushdown( int u ) 
{
    if( !tr[u].add ) return;
    ll t = tr[u].add;
    tr[ls].sum = ( tr[ls].sum + t * ( tr[ls].r - tr[ls].l + 1 ) ) % mod;
    tr[rs].sum = ( tr[rs].sum + t * ( tr[rs].r - tr[rs].l + 1 ) ) % mod;
    tr[ls].add = ( tr[ls].add + t ) % mod;
    tr[rs].add = ( tr[rs].add + t ) % mod;
    tr[u].add = 0;
}

void build( int u, int l, int r ) 
{
    tr[u] = { l, r, 0, 0 };
    if( l == r ) 
    {
        tr[u].sum = w[rnk[l]] % mod;
        return;
    }
    int mid = l + r >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    pushup( u );
}

void modify( int u, int l, int r, ll val ) 
{
    if( l <= tr[u].l && tr[u].r <= r ) 
    {
        tr[u].sum = ( tr[u].sum + val * ( tr[u].r - tr[u].l + 1 ) ) % mod;
        tr[u].add = ( tr[u].add + val ) % mod;
        return;
    }
    pushdown( u );
    int mid = tr[u].l + tr[u].r >> 1;
    if( l <= mid ) modify( ls, l, r, val );
    if( r > mid ) modify( rs, l, r, val );
    pushup( u );
}

ll query( int u, int l, int r ) 
{
    if( l <= tr[u].l && tr[u].r <= r ) return tr[u].sum;
    pushdown( u );
    int mid = tr[u].l + tr[u].r >> 1;
    ll res = 0;
    if( l <= mid ) res = ( res + query( ls, l, r ) ) % mod;
    if( r > mid ) res = ( res + query( rs, l, r ) ) % mod;
    return res;
}

void dfs1( int u, int p ) 
{
    dep[u] = dep[p] + 1; fa[u] = p; sz[u] = 1;
    for( int v : adj[u] ) 
    {
        if( v == p ) continue;
        dfs1( v, u );
        sz[u] += sz[v];
        if( sz[v] > sz[son[u]] ) son[u] = v;
    }
}

void dfs2( int u, int t ) 
{
    top[u] = t; dfn[u] = ++timer; rnk[timer] = u;
    if( !son[u] ) return;
    dfs2( son[u], t );
    for( int v : adj[u] ) 
    { 
        if( v == fa[u] || v == son[u] ) continue;
        dfs2( v, v );     
    }
}

void modify_path( int u, int v, int val ) 
{
    while( top[u] != top[v] ) 
    {
        if( dep[top[u]] < dep[top[v]] ) swap( u, v );
        modify( 1, dfn[top[u]], dfn[u], val );
        u = fa[top[u]];
    }
    if( dep[u] > dep[v] ) swap( u, v );
    modify( 1, dfn[u], dfn[v], val );
}

ll query_path( int u, int v ) 
{
    ll res = 0;
    while( top[u] != top[v] ) 
    {
        if( dep[top[u]] < dep[top[v]] ) swap( u, v );
        res = ( res + query( 1, dfn[top[u]], dfn[u] ) ) % mod;
        u = fa[top[u]];
    }
    if( dep[u] > dep[v] ) swap( u, v );
    res = ( res + query( 1, dfn[u], dfn[v] ) ) % mod;
    return res;
}

int main( ) 
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n >> m >> r >> mod;

    for( int i = 1; i <= n; ++ i ) cin >> w[i];
    
    for( int i = 1; i < n; ++ i ) 
    {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }

    dfs1( r, 0 );
    dfs2( r, r );
    build( 1, 1, n );

    while( m -- ) 
    {
        int opt, x, y, z;
        cin >> opt;
        if( opt == 1 ) { 
            cin >> x >> y >> z; 
            modify_path( x, y, z ); 
        } else if( opt == 2 ) { 
            cin >> x >> y; 
            cout << query_path( x, y ) << '\n'; 
        } else if( opt == 3 ) { 
            cin >> x >> z; 
            modify( 1, dfn[x], dfn[x] + sz[x] - 1, z ); 
        } else { 
            cin >> x; 
            cout << query( 1, dfn[x], dfn[x] + sz[x] - 1 ) << '\n'; 
        }
    }
    return 0;
}