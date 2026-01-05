#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int a[maxn];
int n;

void solve( )
{
	cin >> n;
	a[0] = 1e9, a[n + 1] = 1e9;

	for( int i = 1; i <= n; ++ i ) 
	{
		cin >> a[i];
	}

	int ans = 0, max_num = 0;
	for( int i = 1; i <= n; ++ i )
	{
		max_num = max(a[i], max_num);
		if( i % 2 == 0 ) a[i] = max_num;
	}
	
	for( int i = 1; i <= n; i += 2 )
	{
		int min_num = min(a[i - 1] , a[i + 1]);
		if( min_num <= a[i] ) ans += a[i] - min_num + 1;
	}

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
