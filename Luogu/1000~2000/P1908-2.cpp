#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;

struct Info {
    ll cnt = 0;
    static Info merge( const Info& l, const Info& r ) {
        return { l.cnt + r.cnt };
    }
};

struct Node {
    int l, r;
    Info info;
} tr[maxn << 2];

#define ls (u << 1)
#define rs (u << 1 | 1)

void push_up( int u ) { 
    tr[u].info = Info::merge( tr[ls].info, tr[rs].info ); 
}

void build( int u, int l, int r ) 
{
    tr[u].l = l, tr[u].r = r;
    if( l == r ) 
    {
        tr[u].info = { 0 };
        return;
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify( int u, int pos, int val ) 
{
    if( tr[u].l == tr[u].r )
    {
        tr[u].info.cnt += val;
        return;
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( pos <= mid ) modify( ls, pos, val );
    else modify( rs, pos, val );
    push_up( u );
}

Info query( int u, int l, int r ) 
{
    if( l > r ) return { 0 };
    if( l <= tr[u].l && tr[u].r <= r ) return tr[u].info;
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( r <= mid ) return query( ls, l, r );
    if( mid < l ) return query( rs, l, r );
    return Info::merge( query( ls, l, r ), query( rs, l, r ) );
}

vector< int > ys;
int n;

int getId( int x ) {
    return lower_bound( ys.begin( ), ys.end( ), x ) - ys.begin( ) + 1;
}

void solve( )
{
    cin >> n;
    vector< int > a(n);
    for( int i = 0; i < n; ++ i )
    {
        cin >> a[i];
        ys.push_back( a[i] );
    }

    sort( ys.begin( ), ys.end( ) );
    ys.erase( unique( ys.begin( ), ys.end( ) ), ys.end( ) );

    int m = ys.size( );
    build( 1, 1, m );

    ll ans = 0;
    for( int i = 0; i < n; ++ i )
    {
        int rank = getId( a[i] );
        ans += query( 1, rank + 1, m ).cnt;
        modify( 1, rank, 1 );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}