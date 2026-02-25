#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
ll mod = 1e18;

struct Info {
    ll maxv, ans, pre, suf, len;
};

Info merge( const Info& l, const Info& r )
{
    Info res;
    int len = l.len + r.len;

    if( l.maxv > r.maxv )
    {
        res = { l.maxv, l.ans, l.pre, 0, len };
    }
    else if( l.maxv < r.maxv )
    {
        res = { r.maxv, r.ans, 0, r.suf, len };
    }
    else
    {
        res.maxv = l.maxv;
        res.ans = l.ans + r.ans + l.suf * r.pre;
        res.pre = l.pre + ( l.pre == l.len ? r.pre : 0 );
        res.suf = r.suf + ( r.suf == r.len ? l.suf : 0 );
        res.len = len;
    }
    return res;
}

struct Node {
    int l, r;
    Info info;
} tr[maxn << 2];

int n, q;
ll a[maxn];

#define ls (u << 1)
#define rs (u << 1 | 1)

void push_up( int u ) { 
    tr[u].info = merge( tr[ls].info, tr[rs].info ); 
}

void build( int u, int l, int r ) 
{
    tr[u].l = l, tr[u].r = r;
    if( l == r ) 
    {
        tr[u].info = { 0, 1, 1, 1, 1 };
        return;
    }
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
    push_up( u );
}

void modify( int u, int k, int val ) 
{
    if( tr[u].l == tr[u].r ) 
    {
        tr[u].info.maxv = val;
        return;
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( k <= mid ) modify( ls, k, val );
    else modify( rs, k, val );
    push_up( u );
}

void solve( )
{
    cin >> n >> q;
    
    vector< set< int > > pos( n + 1 );
    build( 1, 1, n );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        pos[a[i]].insert( i );
    }

    for( int v = 1; v <= n; ++ v )
    {
        if( pos[v].empty( ) ) continue;
        int l = *pos[v].begin( ), r = *pos[v].rbegin( );
        modify( 1, l, r - l );
    }

    for( int i = 1; i <= q; ++ i )
    {
        int idx, val;
        cin >> idx >> val;
        
        int oldv = a[idx];

        if( oldv != val )
        {
            // delete oldv
            int oldl = *pos[oldv].begin( );
            modify( 1, oldl, 0 );
            pos[oldv].erase( idx );

            if( !pos[oldv].empty( ) )
            {
                int newl = *pos[oldv].begin( );
                int newr = *pos[oldv].rbegin( );
                modify( 1, newl, newr - newl );
            }

            // insert val
            if( !pos[val].empty( ) )
            {
                int newl = *pos[val].begin( );
                modify( 1, newl, 0 );
            }
            
            pos[val].insert( idx );
            int newl = *pos[val].begin( );
            int newr = *pos[val].rbegin( );
            modify( 1, newl, newr - newl );

            a[idx] = val;
        }

        if( tr[1].info.maxv == 0 ) {
            cout << 0 << " " << 0 << '\n';
        } else {
            cout << tr[1].info.maxv << " " << tr[1].info.ans << '\n';
        }
    }
}

int main( )
{
    ios::sync_with_stdio( false );
    cin.tie( 0 );
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}