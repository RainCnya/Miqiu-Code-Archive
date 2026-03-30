#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int maxn = 1e6 + 5;

ll a[maxn], b[maxn];
ll f[maxn];
int n;

int LIS( vector<ll> &nums )
{
    memset( f, 0, sizeof f );
	ll len = 0;
    for( ll x : nums )
    {
        int pos = upper_bound( f + 1, f + len + 1, x ) - f;
        f[pos] = x;
        if( pos > len ) len = pos;
    }
    return len;
}

struct Tag {
    ll add = 0;
    bool empty( ) { return add == 0; }
    void clear( ) { add = 0; }
    void apply( const Tag& t ) { add = (add + t.add); }
};

struct Info {
    ll sum = 0, len = 0;
    static Info merge( const Info& l, const Info& r ) {
        return { l.sum + r.sum, l.len + r.len };
    }
    void update( const Tag& t ) {
        sum = ( sum + t.add * len );
    }
};

struct Node {
    int l, r;
    Info info;
    Tag tag;
} tr[maxn << 2];

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
        tr[u].info = { b[l], 1 };
        return;
    }
    int mid = ( l + r ) >> 1;
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
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify( ls, l, r, t );
    if( mid < r ) modify( rs, l, r, t );
    push_up( u );
}

Info query( int u, int l, int r ) 
{
    if( l <= tr[u].l && tr[u].r <= r ) return tr[u].info;
    push_down( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( r <= mid ) return query( ls, l, r );
    if( mid < l ) return query( rs, l, r );
    return Info::merge( query( ls, l, r ), query( rs, l, r ) );
}

int cnt= 1;

void solve( )
{
    cout << "Case#" << cnt ++ << ":" << '\n';

    cin >> n;
    vector<int> nums;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
        nums.push_back( a[i] );
    }

    int len = LIS( nums );
    sort( a + 1, a + n + 1 );
    for( int i = 1; i <= len; ++ i ) b[i] = a[i];
    for( int i = len + 1; i <= n; ++ i ) b[i] = 0;

    build( 1, 1, n );

    int m;
    cin >> m;
    while( m -- )
    {
        string s;
        int x, y; ll z;
        cin >> s;
        if( s == "feed" ) 
        {
            cin >> x >> y >> z;
            if( x > len ) continue;
            y = min( y, len );
            modify( 1, x, y, Tag{ z } );
        }
        else 
        {
            cin >> x >> y;
            if( x > len ) {
                cout << 0 << '\n';
                continue;
            }
            y = min( y, len );
            cout << query( 1, x, y ).sum << '\n';
        }
    }
}

signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}