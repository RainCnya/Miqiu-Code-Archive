#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 50;

ll a[maxn];
int n;
ll C;

struct Node {
    int l, r;
    ll mx;
} tr[ maxn << 2 ];

#define ls ( u << 1 )
#define rs ( u << 1 | 1 )

void push_up( int u ) {
    tr[u].mx = max( tr[ls].mx, tr[rs].mx );
}

void build( int u, int l, int r )
{
    tr[u] = { l, r, 0 };
    if( l == r ) 
    {
        tr[u].mx = C;
        return ;
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void update( int u, int idx, ll val )
{
    if( tr[u].l == tr[u].r )
    {
        tr[u].mx = val;
        return ;
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( idx <= mid ) update( ls, idx, val );
    else update( rs, idx, val );
    push_up( u );
}

int query( int u, ll val )
{
    if( tr[u].l == tr[u].r ) return tr[u].l;
    if( tr[ls].mx >= val ) return query( ls, val );
    else return query( rs, val );
}

ll remain[maxn];

int solve1( )
{
    build( 1, 1, n );
    for( int i = 1; i <= n; ++ i ) remain[i] = C;

    int max_idx = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int idx = query( 1, a[i] );
        max_idx = max( max_idx, idx );

        remain[idx] -= a[i];
        update( 1, idx, remain[idx] );
    }
    return max_idx;
}

int solve2( )
{
    multiset< ll > s;
    for( int i = 1; i <= n; ++ i )
    {
        auto it = s.lower_bound( a[i] );
        if( it == s.end( ) )
        {
            s.insert( C - a[i] );
        }
        else
        {
            ll val = *it - a[i];
            s.erase( it );
            s.insert( val );
        }
    }
    return s.size( );
}

void solve( )
{
    cin >> n >> C;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    int first = solve1( );
    int best = solve2( );
    cout << first << " " << best << '\n';
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