#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 5;
const int maxV = 1e6 + 5;

int n, q, idx;
int root[maxn];

struct Node {
    int l, r, cnt;
    ll sum;
} tr[maxn << 5];

void modify( int &u, int v, int l, int r, int val )
{
    u = ++ idx;
    tr[u] = tr[v];
    tr[u].cnt ++, tr[u].sum += val;
    if( l == r ) return ;

    int mid = ( l + r ) >> 1;
    if( val <= mid ) modify( tr[u].l, tr[v].l, l, mid, val );
    else modify( tr[u].r, tr[v].r, mid + 1, r, val );
}

ll query( int u, int v, int l, int r, int k )
{
    if( l == r ) return l * k;

    int mid = ( l + r ) >> 1;
    int rcnt = tr[tr[v].r].cnt - tr[tr[u].r].cnt;
    
    if( k <= rcnt ) return query( tr[u].r, tr[v].r, mid + 1, r, k );
    else {
        ll rsum = tr[tr[v].r].sum - tr[tr[u].r].sum;
        return query( tr[u].l, tr[v].l, l, mid, k - rcnt ) + rsum;
    }
}

ll calc( ll m )
{
    return m * ( m + 1 ) * ( 2 * m + 1 ) / 6;
}

void solve( )
{
    cin >> n;

    idx = 0, root[0] = 0;
    tr[0] = { 0, 0, 0, 0 };

    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        modify( root[i], root[i - 1], 1, maxV, x );
    }

    cin >> q;
    for( int i = 1; i <= q; ++ i )
    {
        int l, r, k;
        cin >> l >> r >> k;
        int m = r - l + 1;
        ll ans = calc( m ) + query( root[l - 1], root[r], 1, maxV, k );
        cout << ans << '\n';
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