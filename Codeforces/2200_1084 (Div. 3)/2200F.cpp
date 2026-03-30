#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 4e5 + 5;

ll bit_sum[maxn], bit_cnt[maxn];
ll pre[maxn];
vector< ll > nums;
int n, m, sz;

void add( ll bit[], int idx, ll val ) {
    for( int i = idx; i <= sz; i += i & -i ) bit[i] += val;
}

ll query( int k ) {
    int idx = 0, res_cnt = 0;
    ll res_sum = 0;
    for( int i = ( 1 << 18 ); i > 0; i >>= 1 ) {
        if( idx + i <= sz && res_cnt + bit_cnt[idx + i] < k ) {
            idx += i;
            res_cnt += bit_cnt[idx];
            res_sum += bit_sum[idx];
        }
    }
    if( idx < sz ) {
        int need = k - res_cnt;
        res_sum += need * nums[idx];
    }
    return res_sum;
}

void solve( )
{
    cin >> n >> m;
    
    nums.clear( );
    vector< vector< ll > > ytox( n + 1 );

    for( int i = 1; i <= n; ++ i )
    {
        ll x, y; cin >> x >> y;
        nums.push_back( x );
        ytox[y].push_back( x );
    }

    sort( nums.begin( ), nums.end( ), greater< ll >( ) );
    nums.erase( unique( nums.begin( ), nums.end( ) ), nums.end( ) );
    sz = nums.size( );

    for( int i = 0; i <= sz; ++ i ) bit_cnt[i] = bit_sum[i] = 0;
    for( int i = 0; i <= n; ++ i ) pre[i] = 0;

    ll maxx = 0;
    for( int y = n; y >= 0; -- y )
    {
        for( ll x : ytox[y] )
        {
            int idx = lower_bound( nums.begin( ), nums.end( ), x, greater< ll >( ) ) - nums.begin( ) + 1;
            add( bit_cnt, idx, 1 );
            add( bit_sum, idx, x );
        }

        pre[y] = query( y );
        if( y + 1 <= n ) maxx = max( maxx, query( y + 1 ) );
    }

    for( int i = 1; i <= n; ++ i ) pre[i] = max( pre[i], pre[i - 1] );

    for( int j = 1; j <= m; ++ j )
    {
        ll x, y; cin >> x >> y;
        ll ans = max( maxx, x + pre[y] );
        cout << ans << ' ';
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}