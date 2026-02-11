#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;
const int mod = 201314;

vector< int > adj[maxn];
int fa[maxn], dep[maxn], sz[maxn], son[maxn];
int top[maxn], dfn[maxn], rnk[maxn], timer;
ll ans[maxn];
int n, m;

struct Node {
    int l, r;
    ll sum, add;
} tr[maxn << 2];

#define ls u << 1
#define rs u << 1 | 1

void pushup( int u ) 
{
    tr[u].sum = (tr[ls].sum + tr[rs].sum) % mod;
}

void pushdown( int u ) 
{
    if( tr[u].add == 0 ) return ;
    tr[ls].sum = (tr[ls].sum + tr[u].add * (tr[ls].r - tr[ls].l + 1)) % mod;
    tr[rs].sum = (tr[rs].sum + tr[u].add * (tr[rs].r - tr[rs].l + 1)) % mod;
    tr[ls].add = (tr[ls].add + tr[u].add) % mod;
    tr[rs].add = (tr[rs].add + tr[u].add) % mod;
    tr[u].add = 0;
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r;
    tr[u].add = 0;
    if( l == r ) 
    {
        tr[u].sum = 0;
        return ;
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    pushup( u );
}

void modify( int u, int l, int r, int val )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].sum = (tr[u].sum + val * (tr[u].r - tr[u].l + 1)) % mod;
        tr[u].add = (tr[u].add + val) % mod;
        return ;
    }    
    pushdown( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify( ls, l, r, val );
    if( mid < r ) modify( rs, l, r, val );
    pushup( u );
}

ll query( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r ) return tr[u].sum;
    pushdown( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    ll res = 0;
    if( l <= mid ) res = ( res + query( ls, l, r ) ) % mod;
    if( r > mid ) res = ( res + query( rs, l, r ) ) % mod;
    return res;
}

void dfs1( int u, int p )
{
    fa[u] = p, dep[u] = dep[p] + 1, sz[u] = 1;
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
    top[u] = t, dfn[u] = ++timer, rnk[timer] = u;
    if( son[u] == 0 ) return ;
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

struct Task {
    int pos, z, id, opt;
    bool operator < ( const Task& oth ) const { return pos < oth.pos; }
};

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for( int i = 1; i < n; ++ i )
    {
        int p; cin >> p;
        adj[p + 1].push_back( i + 1 );
    }

    dfs1( 1, 0 );
    dfs2( 1, 1 );
    build( 1, 1, n );

    vector< Task > tasks;
    for( int i = 1; i <= m; ++ i )
    {
        int l, r, z; 
        cin >> l >> r >> z;
        l ++, r ++, z ++;
        tasks.push_back({ l - 1, z, i, -1 });
        tasks.push_back({ r, z, i, 1 });
    }

    sort( tasks.begin( ), tasks.end( ) );

    int cur = 0;
    for( auto [pos, z, id, opt] : tasks )
    {
        while( cur < pos )
        {
            cur ++;
            modify_path( 1, cur, 1 );
        }
        ll res = query_path( 1, z );
        ans[id] = ( ans[id] + res * opt + mod ) % mod;
    }

    for( int i = 1; i <= m; ++ i ) cout << ans[i] << '\n';
    return 0;
}