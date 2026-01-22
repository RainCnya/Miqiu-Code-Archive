#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

#define ls u << 1
#define rs u << 1 | 1

const int maxn = 2e5 + 50;
const int inf = 0x3f3f3f3f;

struct Line {
    ll x, y1, y2;
    int k;
    bool operator < ( const Line &other ) {
        return x < other.x;
    }
} lines[maxn];

ll raw_y[maxn];

struct Node {
    int l, r;
    int cnt;
    ll len;
} tr[maxn << 3];

int n;

void push_up( int u )
{
    if( tr[u].cnt > 0 ) {
        tr[u].len = raw_y[tr[u].r + 1] - raw_y[tr[u].l];
    }
    else if( tr[u].l != tr[u].r ) {
        tr[u].len = tr[ls].len + tr[rs].len;
    } 
    else {
        tr[u].len = 0;
    }
}

void build( int u, int l, int r )
{
    tr[u] = {l, r, 0, 0};
    if( l == r ) return ;
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid+1, r );
}

void modify( int u, int l, int r, int k )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].cnt += k;
        push_up( u );
        return ;
    }    
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify( ls, l, r, k );
    if( mid < r ) modify( rs, l, r, k );
    push_up( u );
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[2 * i - 1] = {x1, y1, y2, 1};
        lines[2 * i] = {x2, y1, y2, -1};
        raw_y[2 * i - 1] = y1;
        raw_y[2 * i] = y2;
    }

    n *= 2;
    sort( lines + 1, lines + n + 1 );
    sort( raw_y + 1, raw_y + n + 1 );

    int m = unique( raw_y + 1, raw_y + n + 1 ) - raw_y - 1;

    if( m > 0 ) build( 1, 1, m - 1 );

    ll ans = 0;
    for( int i = 1; i < n; ++ i )
    {
        int l = lower_bound( raw_y + 1, raw_y + m + 1, lines[i].y1 ) - raw_y;
        int r = lower_bound( raw_y + 1, raw_y + m + 1, lines[i].y2 ) - raw_y;

        if( l < r ) modify( 1, l, r - 1, lines[i].k );
        ans += (ll)tr[1].len * ( lines[i+1].x - lines[i].x );
    }

    cout << ans << '\n';
    return 0;
}