#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

struct Tag {
    ll add = 0;
    bool exist( ) { return add != 0; }
    void clear( ) { add = 0; }
    void apply( const Tag& t ) {
        add = (add + t.add);
    }
};

struct Info {
    ll sum = 0;
    ll len = 0;
    static Info merge( const Info& l, const Info& r ) {
        return { (l.sum + r.sum), l.len + r.len };
    }
    void update( const Tag& t ) {
        sum = (sum + t.add * len);
    }
};

struct Node {
    int l, r;
    Info info;
    Tag tag;
} tr[ maxn << 2 ];

int n, m;
ll a[maxn];

#define ls (u << 1)
#define rs (u << 1 | 1)

void push_up( int u ) {
    tr[u].info = Info::merge( tr[ls].info, tr[rs].info );
}

void push_down( int u ) {
    if( tr[u].tag.exist( ) )
    {
        tr[ls].info.update( tr[u].tag );
        tr[rs].info.update( tr[u].tag );
        tr[ls].tag.apply( tr[u].tag );
        tr[rs].tag.apply( tr[u].tag );
        tr[u].tag.clear( );
    }
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r;
    tr[u].tag.clear( );
    if( l == r )
    {
        tr[u].info = {a[l], 1};
        return;
    }
    int mid = (l + r) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify( int u, int l, int r, const Tag& t )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].info.update( t );
        tr[u].tag.apply( t );
        return;
    }
    push_down( u );
    int mid = (tr[u].l + tr[u].r) >> 1;
    if( l <= mid ) modify( ls, l, r, t );
    if( mid < r ) modify( rs, l, r, t );
    push_up( u );
}

ll query( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        return tr[u].info.sum;
    }
    push_down( u );
    int mid = (tr[u].l + tr[u].r) >> 1;
    ll res = 0;
    if( l <= mid ) res += query( ls, l, r );
    if( mid < r ) res += query( rs, l, r );
    return res;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    build( 1, 1, n );

    for( int i = 1; i <= m; ++ i )
    {
        int opt, x, y;
        ll k;
        cin >> opt >> x >> y;
        if( opt == 1 ) 
        {
            cin >> k;
            modify( 1, x, y, Tag{ k } );
        }
        else
        {
            cout << query( 1, x, y ) << '\n';
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}