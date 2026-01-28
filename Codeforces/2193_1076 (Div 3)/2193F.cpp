#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

struct Point {
    ll x, y;
} a[maxn], st, ed;

struct Seg {
    ll ymin, ymax;
} last, cur;

ll dpmin[maxn], dpmax[maxn];

bool cmp( const Point &a, const Point &b )
{
    if( a.x == b.x ) return a.y < b.y;
    return a.x < b.x;
}

void solve( )
{
    int n;
    cin >> n >> st.x >> st.y >> ed.x >> ed.y;
    
    for( int i = 1; i <= n; ++ i ) cin >> a[i].x;
    for( int i = 1; i <= n; ++ i ) cin >> a[i].y;
    a[n + 1] = { ed.x, ed.y };

    sort( a + 1, a + n + 1, cmp );

    int pos = 0;
    last = { st.y, st.y };
    dpmin[0] = dpmax[0] = 0;

    for( int l = 1; l <= n + 1; )
    {
        int r = l;
        while( r <= n + 1 && a[r].x == a[l].x ) r ++;

        cur = { a[l].y, a[r-1].y };
        ll len = cur.ymax - cur.ymin;
        pos ++;

        dpmin[pos] = min( dpmin[pos-1] + abs( last.ymin - cur.ymax ), dpmax[pos-1] + abs( last.ymax - cur.ymax ) ) + len;
        dpmax[pos] = min( dpmin[pos-1] + abs( last.ymin - cur.ymin ), dpmax[pos-1] + abs( last.ymax - cur.ymin ) ) + len;
        last = cur;
        l = r;
    }

    ll ans = abs( ed.x - st.x ) + min( dpmin[pos], dpmax[pos] );
    cout << ans << '\n';
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