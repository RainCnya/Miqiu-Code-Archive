#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
ll cnt = 0;


struct Node {
    int l, r, tag;
    ll s0, s1, s2;
} tr[ maxn << 2 ];

int n, m;

#define ls (u << 1)
#define rs (u << 1 | 1)

void push_up( int u ) {
    tr[u].s0 = tr[ls].s0 + tr[rs].s0;
    tr[u].s1 = tr[ls].s1 + tr[rs].s1;
    tr[u].s2 = tr[ls].s2 + tr[rs].s2;
}

void update_node( int u, int type )
{
    if( type == 0 )
    {
        tr[u].s0 += tr[u].s1 + tr[u].s2;
        tr[u].s1 = tr[u].s2 = 0;
        tr[u].tag = 0;
    }
    else if( type == 1 )
    {
        tr[u].s1 += tr[u].s0;
        tr[u].s0 = 0;
        tr[u].tag = 1;
    }
}

void push_down( int u ) 
{
    if( tr[u].tag == -1 ) return;
    update_node( ls, tr[u].tag );
    update_node( rs, tr[u].tag );
    tr[u].tag = -1;
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r, tr[u].tag = -1;
    if( l == r )
    {
        tr[u].s0 = 0, tr[u].s1 = 0, tr[u].s2 = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify_cut( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        cnt += tr[u].s1;
        update_node( u, 0 );
        return;
    }

    push_down( u );
    int mid = (tr[u].l + tr[u].r) >> 1;
    if( l <= mid ) modify_cut( ls, l, r );
    if( mid < r ) modify_cut( rs, l, r );
    push_up( u );
}

void modify_grow( int u, int l, int r )
{
    if( tr[u].s0 == 0 ) return;

    if( tr[u].l == tr[u].r )
    {
        if( tr[u].s0 == 1 )
        {
            tr[u].s1 = 1;
            tr[u].s0 = 0;
        }
        return;
    }

    push_down( u );
    int mid = (tr[u].l + tr[u].r) >> 1;
    if( l <= mid ) modify_grow( ls, l, r );
    if( mid < r ) modify_grow( rs, l, r );
    push_up( u );
}

void solve( )
{
    cin >> n >> m;
    build( 1, 0, n );

    for( int i = 1; i <= m; ++ i )
    {
        int op, u, v;
        cin >> op >> u >> v;
        if( op == 0 ) modify_cut( 1, u, v );
        else modify_grow( 1, u, v );
    }

    cout << tr[1].s1 << '\n' << cnt << '\n';
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