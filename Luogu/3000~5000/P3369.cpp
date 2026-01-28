#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

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
    tr[u].info = { 0 };
    if( l == r ) return;
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

int find( int u, int k )
{
    if( tr[u].l == tr[u].r ) return tr[u].l;
    if( k <= tr[ls].info.cnt ) return find( ls, k );
    else return find( rs, k - tr[ls].info.cnt );
}

struct Query {
    int opt, x;
} qs[maxn];

vector< int > nums;

int n, m;

int getID( int x ) {
    return lower_bound( nums.begin( ), nums.end( ), x ) - nums.begin( ) + 1;
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> qs[i].opt >> qs[i].x;
        if( qs[i].opt != 4 ) nums.push_back( qs[i].x );
    }

    sort( nums.begin( ), nums.end( ) );
    nums.erase( unique( nums.begin( ), nums.end( ) ), nums.end( ) );

    int m = nums.size( );
    build( 1, 1, m );

    for( int i = 1; i <= n; ++ i )
    {
        auto [opt, x] = qs[i];
        int id = getID( x );

        if( opt == 1 ) {
            modify( 1, id, 1 );
        } else if( opt == 2 ) {
            modify( 1, id, -1 );
        } else if( opt == 3 ) {
            cout << query( 1, 1, id - 1 ).cnt + 1 << '\n';
        } else if( opt == 4 ) { 
            cout << nums[ find( 1, x ) - 1 ] << '\n';
        } else if( opt == 5 ) {
            int cnt = query( 1, 1, id - 1 ).cnt;
            cout << nums[ find( 1, cnt ) - 1 ] << '\n';
        }
        else {
            int cnt = query( 1, 1, id ).cnt;
            cout << nums[ find( 1, cnt + 1 ) - 1 ] << '\n';
        }
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}