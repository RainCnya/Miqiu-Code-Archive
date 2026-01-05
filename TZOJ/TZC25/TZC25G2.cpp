#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100050;
const ll inf = 1e18;

ll a[ maxn ];
ll p[ maxn ];
ll vals[ maxn ];
int dp[ maxn ];
int bit[ maxn ];
int m;

int lowbit( int x )
{
    return x & -x;
}

void update( int idx, int val )
{
    for( ; idx <= m; idx += lowbit( idx ) )
    {
        bit[ idx ] = min( bit[ idx ], val );
    }
}

int query( int idx )
{
    int res = maxn;
    for( ; idx > 0; idx -= lowbit( idx ) )
    {
        res = min( res, bit[ idx ] );
    }
    return res;
}

bool check( ll mid, int n, int k )
{
    for( int i = 0; i <= m; ++ i ) bit[ i ] = maxn;

    int id0 = lower_bound( vals + 1, vals + m + 1, 0 ) - vals;	
    update( m - id0 + 1, 0 );

    for( int i = 1; i <= n; ++ i )
    {
        int idx = lower_bound( vals + 1, vals + m + 1, p[ i ] - mid ) - vals;
        int min_val = query( m - idx + 1 );
        
        if( min_val >= maxn ) dp[ i ] = maxn;
        else dp[ i ] = min_val + 1;

        int cur_id = lower_bound( vals + 1, vals + m + 1, p[ i ] ) - vals;	
        update( m - cur_id + 1, dp[ i ] );
    }

    return dp[ n ] <= k;
}

void solve( )
{
    int n, k;
	cin >> n >> k;

    p[ 0 ] = 0;
    vals[ 1 ] = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[ i ];
        p[ i ] = p[ i - 1 ] + a[ i ];
        vals[ i + 1 ] = p[ i ];
    }

    sort( vals + 1, vals + n + 2 );
    m = unique( vals + 1, vals + n + 2 ) - ( vals + 1 );

    ll l = -1e18, r = 1e18, ans = 1e18;

    while( l <= r )
    {
        ll mid = l + ( r - l ) / 2;
        if( check( mid, n, k ) ) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    cout << ans << "\n";
}

int main( )
{
    ios::sync_with_stdio( 0 );
    cin.tie( 0 );
    int _t = 1;
	cin >> _t;
	while( _t -- )	solve( );
    return 0;
}