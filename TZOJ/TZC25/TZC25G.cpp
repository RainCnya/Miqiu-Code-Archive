#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const ll inf = 1e18;

ll a[maxn];
ll n, k;

bool check( ll mid )
{
	ll sum = 0;
	ll cnt = 0;
	ll max_sum = -inf;
	for( int i = 1; i <= n; ++ i )
	{
		if( sum + a[i] > mid )
		{
			cnt ++;
			max_sum = max( max_sum, sum );
			sum = 0;
		}
		sum += a[i];
	}
	if( sum != 0 ) cnt ++;
//	cout << cnt << '\n';
	return cnt <= k && max_sum <= mid;
}

void solve( )
{
	cin >> n >> k;
	
	for( int i = 1; i <= n; ++ i ) cin >> a[i];
	
	ll l = -inf, r = inf;
	ll ans = 0;
	while( l <= r )
	{
		ll mid = ( l + r ) >> 1;
		//printf("%lld %lld %lld\n", l, mid ,r );
		
		if( check( mid ) ) ans = mid, r = mid - 1;
		else l = mid + 1;
		//cout << ans << '\n';
	}
	cout << ans << '\n';
}

int main( )
{
	int _t;
	cin >> _t;
	while( _t -- )
	{
		solve( );
	}
	return 0;
}
