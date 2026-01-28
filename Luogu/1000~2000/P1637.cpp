#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e4 + 5;
const int maxv = 1e5 + 5;

struct Info {
    ll cnt = 0;
    static Info merge( const Info& l, const Info& r ) {
        return { l.cnt + r.cnt };
    }
};

struct Node {
    int l, r;
    Info info;
} tr[maxv << 2];

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

int n;
int a[maxn];
ll L[maxn], R[maxn];

void solve( )
{
    cin >> n;
    int max_val = 0;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        max_val = max( max_val, a[i] );
    }

    build( 1, 1, max_val );
    for( int i = 1; i <= n; ++ i )
    {
        L[i] = query( 1, 1, a[i] - 1 ).cnt;
        modify( 1, a[i], 1 );
    }

    build( 1, 1, max_val );
    for( int i = n; i >= 1; -- i )
    {
        R[i] = query( 1, a[i] + 1, max_val ).cnt;
        modify( 1, a[i], 1 );
    }

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans += L[i] * R[i];
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