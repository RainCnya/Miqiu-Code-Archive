#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

struct Info {
    ll cnt = 0, sum = 0;
    static Info merge( const Info& l, const Info& r ) {
        return { l.cnt + r.cnt, l.sum + r.sum };
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
    tr[u].info = { 0, 0 };
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
        tr[u].info.sum += tr[u].l * val;
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

int n, m;
int p[maxn];
int c[maxn];

struct Bit {
    int t[maxn];
    void add( int idx , int val ) {
        for( int i = idx; i <= n; i += i & -i ) t[i] += val;
    }
    ll query( int idx ) {
        ll res = 0;
        for( int i = idx; i; i -= i & -i ) res += t[i];
        return res;
    }
} bit;

void solve( )
{
    cin >> n >> m;
    build( 1, 0, n - 1 );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> p[i];
        c[i] = ( i - 1 ) - bit.query( p[i] );
        bit.add( p[i], 1 );
        modify( 1, c[i], 1 );
    }

    while( m -- )
    {
        int t, k;
        cin >> t >> k;
        if( t == 1 )
        {
            modify( 1, c[k], -1 );
            modify( 1, c[k + 1], -1 );
                
            if( p[k] < p[k + 1] ) c[k] ++;
            else c[k + 1] -- ;

            swap( p[k], p[k + 1] );
            swap( c[k], c[k + 1] );

            modify( 1, c[k], 1 );
            modify( 1, c[k + 1], 1 );
        }
        else
        {
            if( k >= n - 1 ) 
            {
                cout << 0 << '\n';
            }
            else 
            {
                Info res = query( 1, k + 1, n - 1 );
                cout << res.sum - k * res.cnt << '\n';
            }
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