#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

#define ls u << 1
#define rs u << 1 | 1

const int maxn = 5e5 + 50;
const int inf = 0x3f3f3f3f;

struct Node {
    int l, r;
    int sum, dat;
    int lmax, rmax;
} tr[maxn << 2];

int a[maxn];
int n, m;

Node merge( const Node &L, const Node &R )
{
    Node res;
    res.l = L.l, res.r = R.r;
    res.sum = L.sum + R.sum;
    res.lmax = max( L.lmax, L.sum + R.lmax );
    res.rmax = max( R.rmax, R.sum + L.rmax );
    res.dat = max( max( L.dat, R.dat ), R.lmax + L.rmax );
    return res;
}

void push_up( int u )
{
    int l = tr[u].l, r = tr[u].r;
    tr[u] = merge( tr[ls], tr[rs] );
    tr[u].l = l, tr[u].r = r;
}

void build( int u, int l, int r )
{
    tr[u].l = l, tr[u].r = r;
    if( l == r ) {
        tr[u].sum = tr[u].lmax = tr[u].rmax = tr[u].dat = a[l];
        return ;
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid+1, r );
    push_up( u );
}

void modify( int u, int x, int v )
{
    if( tr[u].l == tr[u].r ) {
        tr[u].sum = tr[u].lmax = tr[u].rmax = tr[u].dat = v;
        return ;
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( x <= mid ) modify( ls, x, v );
    else modify( rs, x, v );
    push_up( u );
}

Node query( int u, int l, int r )
{
    if( l <= tr[u].l && tr[u].r <= r ) {
        return tr[u];
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;

    if( r <= mid ) return query( ls, l, r );
    if( mid < l ) return query( rs, l, r );
    
    Node res_l = query( ls, l, r );
    Node res_r = query( rs, l, r );
    return merge( res_l, res_r );
}

int main( )
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 ), cout.tie( 0 );

    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    build( 1, 1, n );

    for( int i = 1; i <= m; ++ i )
    {
        int k, x, y;
        cin >> k >> x >> y;
        if( k == 1 )
        {
            if( x > y ) swap( x, y );
            cout << query( 1, x, y ).dat << '\n';
        }
        else
        {
            modify( 1, x, y );
        }
    }
    return 0;
}