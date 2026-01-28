#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
ll mod;

struct Info {
    ll prod = 1;
    static Info merge( const Info& l, const Info& r ) {
        return { (l.prod * r.prod) % mod };
    }
};

struct Node {
    int l, r;
    Info info;
} tr[ maxn << 2 ];

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
        tr[u].info = { 1 };
        return;
    }
    int mid = (l + r) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify( int u, int pos, ll val )
{
    if( tr[u].l == tr[u].r )
    {
        tr[u].info.prod = val % mod;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if( pos <= mid ) modify( ls, pos, val );
    else modify( rs, pos, val );
    push_up( u );
}

void solve( )
{
    int Q;
    cin >> Q >> mod;
    build( 1, 1, Q );

    for( int i = 1; i <= Q; ++ i )
    {
        ll op, v;
        cin >> op >> v;
        if( op == 1 ) modify( 1, i, v );
        else modify( 1, v, 1 );
        cout << tr[1].info.prod << '\n';
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}