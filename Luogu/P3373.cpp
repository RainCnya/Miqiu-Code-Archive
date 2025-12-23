#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;

#define ls u << 1
#define rs u << 1 | 1

ll a[maxn];
int n, m;
ll p;

struct Node {
    int l, r;
    ll sum, mul, add;
}tr[maxn << 2]; 

void push_up( int u )
{
    tr[u].sum = ( tr[ls].sum + tr[rs].sum ) % p;
}

void push_down( int u )
{
    ll mtag = tr[u].mul;
    ll atag = tr[u].add;

    tr[ls].sum = ( tr[ls].sum * mtag + atag * ( tr[ls].r - tr[ls].l + 1) ) % p;
    tr[ls].mul = ( tr[ls].mul * mtag ) % p;
    tr[ls].add = ( tr[ls].add * mtag + atag ) % p;
    
    tr[rs].sum = ( tr[rs].sum * mtag + atag * ( tr[rs].r - tr[rs].l + 1) ) % p;
    tr[rs].mul = ( tr[rs].mul * mtag ) % p;
    tr[rs].add = ( tr[rs].add * mtag + atag ) % p;

    tr[u].mul = 1;
    tr[u].add = 0;
}

void build( int u, int l, int r )
{
    tr[u] = { l, r, 0, 1, 0 };
    if( l == r )
    {
        tr[u].sum = a[l] % p;
        return ;
    }
    push_down( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify_mul( int u, int l, int r, ll k )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].sum = ( tr[u].sum * k ) % p;
        tr[u].mul = ( tr[u].mul * k ) % p;
        tr[u].add = ( tr[u].add * k ) % p;
        return ;
    }
    push_down( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify_mul( ls, l, r, k );
    if( mid < r ) modify_mul( rs, l, r, k );
    push_up( u );
}

void modify_add( int u, int l, int r, ll k )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].sum = ( tr[u].sum + k * ( tr[u].r - tr[u].l + 1 ) ) % p;
        tr[u].add = ( tr[u].add + k ) % p;
        return ;
    }
    push_down( u );
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify_add( ls, l, r, k );
    if( mid < r ) modify_add( rs, l, r, k );
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
    if( l <= mid ) res = ( res + query( ls, l, r ) ) % p;
    if( mid < r ) res = ( res + query( rs, l, r ) ) % p;
    return res;
}

int main( )
{
    cin >> n >> m >> p;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    build( 1, 1, n );
    
    while( m -- )
    {
        int op, x, y;
        ll k;
        cin >> op >> x >> y;
        if( op == 1 )
        {
            cin >> k;
            modify_mul( 1, x, y, k );
        }
        else if( op == 2 )
        {
            cin >> k;
            modify_add( 1, x, y, k );
        }
        else
        {
            cout << query( 1, x, y ) << '\n';
        }
    }
    
    return 0;
}