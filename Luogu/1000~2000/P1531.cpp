#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
ll mod;

struct Node {
    int l, r;
    ll mx;
} tr[ maxn << 2 ];

int n, m;
ll a[maxn];

#define ls (u << 1)
#define rs (u << 1 | 1)

void push_up( int u ) {
    tr[u].mx = max( tr[ls].mx, tr[rs].mx );
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r;
    if( l == r )
    {
        tr[u].mx = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify( int u, int pos, int val )
{
    if( tr[u].l == tr[u].r )
    {
        if( tr[u].mx < val ) 
            tr[u].mx = val;
        return;
    }
    
    int mid = (tr[u].l + tr[u].r) >> 1;
    if( pos <= mid ) modify( ls, pos, val );
    else modify( rs, pos, val );
    push_up( u );
}

ll query( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        return tr[u].mx;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    ll res = 0;
    if( l <= mid ) res = max( res, query( ls, l, r ) );
    if( mid < r ) res = max( res, query( rs, l, r ) );
    return res;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    build( 1, 1, n );

    while( m -- )
    {
        char op; int a, b;
        cin >> op >> a >> b;
        if( op == 'Q' ) cout << query( 1, a, b ) << '\n';
        else modify( 1, a, b );
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