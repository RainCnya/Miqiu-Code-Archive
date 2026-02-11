#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

vector< int > adj[maxn];
int fa[maxn], dep[maxn], sz[maxn], son[maxn];
int top[maxn], dfn[maxn], timer;
int n, q;

struct Seg {
    int l, r;
    ll sum, add;
} tr[ maxn << 2 ];

#define ls u << 1
#define rs u << 1 | 1

void pushdown( int u ) 
{
    if( !tr[u].add ) return;
    ll t = tr[u].add;
    tr[ls].sum += t * ( tr[ls].r - tr[ls].l + 1 );
    tr[rs].sum += t * ( tr[rs].r - tr[rs].l + 1 );
    tr[ls].add += t;
    tr[rs].add += t;
    tr[u].add = 0;
}

void build( int u, int l, int r ) 
{
    tr[u] = { l, r, 0, 0 };
    if( l == r ) return;
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
}

void modify( int u, int l, int r, ll val ) 
{
    if( l <= tr[u].l && tr[u].r <= r ) 
    {
        tr[u].sum += val * ( tr[u].r - tr[u].l + 1 );
        tr[u].add += val;
        return;
    }
    pushdown( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify( ls, l, r, val );
    if( r > mid ) modify( rs, l, r, val );
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}

ll query( int u, int l, int r ) 
{
    if( l <= tr[u].l && tr[u].r <= r ) return tr[u].sum;
    pushdown( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    ll res = 0;
    if( l <= mid ) res += query( ls, l, r );
    if( r > mid ) res += query( rs, l, r );
    return res;
}

void dfs1( int u, int p ) 
{
    dep[u] = dep[p] + 1; fa[u] = p; sz[u] = 1;
    for( int v : adj[u] ) 
    {
        dfs1( v, u );
        sz[u] += sz[v];
        if( sz[v] > sz[son[u]] ) son[u] = v;
    }
}

void dfs2( int u, int t ) 
{
    top[u] = t; dfn[u] = ++timer;
    if( !son[u] ) return;
    dfs2( son[u], t );
    for( int v : adj[u] ) if( v != son[u] ) dfs2( v, v );
}

ll query_path( int u, int v ) 
{
    ll res = 0;
    while( top[u] != top[v] ) 
    {
        if( dep[top[u]] < dep[top[v]] ) swap( u, v );
        res += query( 1, dfn[top[u]], dfn[u] );
        u = fa[top[u]];
    }
    if( dep[u] > dep[v] ) swap( u, v );
    res += query( 1, dfn[u], dfn[v] );
    return res;
}

int get_lca( int u, int v )
{
    while( top[u] != top[v] ) 
    {
        if( dep[top[u]] < dep[top[v]] ) swap( u, v );
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

struct Quest { 
    int x, y, limit, id, len; 
    bool operator < ( const Quest& oth ) const { return limit < oth.limit; }
};

struct Event {
    int u, time;
    bool operator < ( const Event& oth ) const { return time < oth.time; }
};

int main( ) 
{
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n;
    int root = 1;
    for( int i = 1; i <= n; ++ i ) 
    {
        int p;
        cin >> p;
        if( p == 0 ) root = i;
        else adj[p].push_back( i );
    }

    dfs1( root, 0 );
    dfs2( root, root );
    build( 1, 1, n );

    cin >> q;
    vector< Quest > qs;
    vector< Event > es;

    for( int i = 1; i <= q; ++ i )
    {
        int k, x, y, c, u;
        cin >> k;
        if( k == 1 )
        {
            cin >> x >> y >> c;
            int lca = get_lca( x, y );
            int len = dep[x] + dep[y] - 2 * dep[lca] + 1;
            qs.push_back({ x, y, i - c - 1, (int)qs.size( ), len });
        }
        else
        {
            cin >> u;
            es.push_back({ u, i });
        }
    }

    sort( qs.begin( ), qs.end( ) );
    sort( es.begin( ), es.end( ) );

    vector< pair< int, int > > ans( qs.size( ) );
    int event_idx = 0;

    for( auto q : qs )
    {
        while( event_idx < es.size( ) && es[event_idx].time <= q.limit )
        {
            int u = es[event_idx].u;
            modify( 1, dfn[u], dfn[u], 1 );
            event_idx ++;
        }
        int cnt = query_path( q.x, q.y );
        ans[q.id] = { q.len, cnt };
    }

    for( auto [len, cnt] : ans )
    {
        cout << len << ' ' << cnt << '\n';
    }

    return 0;
}