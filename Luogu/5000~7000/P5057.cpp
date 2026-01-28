#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

struct Tag {
    int rev = 0; // 0 不翻转 \ 1 翻转
    bool empty( ) { return rev == 0; }
    void clear( ) { rev = 0; }
    void apply( const Tag& t ) {
        rev ^= t.rev;
    }
};

struct Info {
    ll sum = 0, len = 0;
    static Info merge( const Info& l, const Info& r ) {
        return { l.sum + r.sum, l.len + r.len };
    }
    void update( const Tag& t ) {
        if( t.rev ) sum = len - sum;
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

void push_down( int u ) 
{
    if( tr[u].tag.empty( ) ) return;
    tr[ls].info.update( tr[u].tag );
    tr[rs].info.update( tr[u].tag );
    tr[ls].tag.apply( tr[u].tag );
    tr[rs].tag.apply( tr[u].tag );
    tr[u].tag.clear( );
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r;
    tr[u].tag.clear( );
    if( l == r )
    {
        tr[u].info = { 0, 1 };
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

ll query( int u, int pos )
{
    if( tr[u].l == tr[u].r ) return tr[u].info.sum;
    push_down( u );
    int mid = (tr[u].l + tr[u].r) >> 1;
    if( pos <= mid ) return query( ls, pos );
    else return query( rs, pos );
}

void solve( )
{
    cin >> n >> m;
    build( 1, 1, n );

    while( m -- )
    {
        int t;
        cin >> t;
        if( t == 1 )
        {
            int l, r;
            cin >> l >> r;
            modify( 1, l, r, Tag{ 1 } );
        }
        else
        {
            int i;
            cin >> i;
            cout << query( 1, i ) << '\n';
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