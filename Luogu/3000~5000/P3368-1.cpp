#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;
int n, m;

inline int lowbit( int x ) { return x & -x; }

// 区间修改，单点查询
struct BIT_RangeAdd_PointQuery {
    ll tr[maxn];

    void add( int idx, ll val ) {
        for( int i = idx; i <= n; i += lowbit( i ) ) tr[i] += val; 
    }
    void rangeAdd( int l, int r, ll val ) {
        add( l, val );
        add( r + 1, -val );
    }
    ll queryPoint( int idx )
    {
        ll res = 0;
        for( int i = idx; i; i -= lowbit( i ) ) res += tr[i];
        return res;
    }
} bit;

int main( )
{
    cin >> n >> m;

    int last = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int curr;
        cin >> curr;
        bit.add( i, curr - last );
        last = curr;
    }

    while( m -- )
    {
        int op, x, y, k;
        cin >> op;
        if( op == 1 )
        {
            cin >> x >> y >> k;
            bit.rangeAdd( x, y, k );
        }
        else
        {
            cin >> x;
            cout << bit.queryPoint( x ) << '\n';
        }
    }
    return 0;
}