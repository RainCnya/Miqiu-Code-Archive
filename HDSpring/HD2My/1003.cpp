#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

struct Node {
    int l, r, pos;
    ll val;
    void operator = ( const Node &oth ) { val = oth.val, pos = oth.pos; }
} tr[maxn << 2];

ll a[maxn];
int n;

#define ls ( u << 1 )
#define rs ( u << 1 | 1 )

void push_up( int u )
{
    if( tr[ls].val >= tr[rs].val ) tr[u] = tr[ls];
    else tr[u] = tr[rs];
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r;
    if( l == r ) { 
        tr[u].val = a[l], tr[u].pos = l;
        return; 
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify( int u, int pos, ll val )
{
    if( tr[u].l == tr[u].r ) { 
        tr[u].val = val; 
        return ; 
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( pos <= mid ) modify( ls, pos, val );
    else modify( rs, pos, val );
    push_up( u );
}

Node query( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r ) return tr[u];
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( r <= mid ) return query( ls, l, r );
    if( mid < l ) return query( rs, l, r );
    
    Node lson = query( ls, l, r );
    Node rson = query( rs, l, r );
    return lson.val >= rson.val ? lson : rson;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    build( 1, 1, n );

    for( int i = 1; i <= n - 1; ++ i )
    {
        int m = ( n + i ) / ( i + 1 );
        ll sum = 0;
        vector< int > tmp;

        for( int k = m; k >= 1; -- k )
        {
            int l = ( k - 1 ) * ( i + 1 ) + 1;
            Node res = query( 1, l, n );
            sum += res.val;
            tmp.push_back( res.pos );
            modify( 1, res.pos, -1 );
        }
        cout << sum << " ";
        for( int t : tmp ) modify( 1, t, a[t] );
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}