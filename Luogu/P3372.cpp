#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;

ll a[maxn];
int n, m;

struct Node {
    int l, r;
    ll sum, tag;
} tr[maxn << 2];

#define ls u << 1
#define rs u << 1 | 1

void push_up( int u )
{
    tr[u].sum = tr[ls].sum + tr[rs].sum;
}

void push_down( int u )
{
    if( tr[u].tag )
    {
        ll t = tr[u].tag;
        tr[ls].sum += t * ( tr[ls].r - tr[ls].l + 1 );
        tr[ls].tag += t;
        tr[rs].sum += t * ( tr[rs].r - tr[rs].l + 1 );
        tr[rs].tag += t;
        tr[u].tag = 0;
    }
}

void build( int u, int l, int r )
{
    tr[u] = { l, r, 0, 0 };
    if( l == r )
    {
        tr[u].sum = a[l];
        return;
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid+1, r );
    push_up( u );
}

void modify( int u, int l, int r, ll k )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].sum += (ll)k * ( tr[u].r - tr[u].l + 1 );
        tr[u].tag += k;
        return ;
    }
    push_down( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify( ls, l, r, k );
    if( mid < r ) modify( rs, l, r, k );
    push_up( u );
}

ll query( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        return tr[u].sum;
    }
    push_down( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    ll res = 0;
    if( l <= mid ) res += query( ls, l, r );
    if( mid < r ) res += query( rs, l, r );
    return res;
}

int main( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }    
    build( 1, 1, n );

    while( m -- )
    {
        int op, x, y;
        ll k;
        cin >> op;
        if( op == 1 )
        {
            cin >> x >> y >> k;
            modify( 1, x, y, k );
        }
        else
        {
            cin >> x >> y;
            cout << query( 1, x, y ) << '\n';
        }
    }
    return 0;
}