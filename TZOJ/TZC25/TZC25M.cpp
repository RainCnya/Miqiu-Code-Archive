#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 50;

ll a[maxn];
ll sum[maxn];
int n;

int main( )
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for( int i = 1; i <= n; ++ i )
	{
		cin >> a[i];
	}
	sort( a + 1, a + n + 1 );
	for( int i = 1; i <= n; ++ i )
	{
		sum[i] = sum[i-1] + a[i];
	}
	
	int q;
	cin >> q;
	while( q -- )
	{
		int k;
		cin >> k;
		if( k == 0 )
		{
			int x;
			cin >> x;
			cout << sum[x] << '\n';
		}
		else
		{
			int x;
			cin >> x;
			cout << sum[n] - sum[n - x] << '\n';
		}
	}
	return 0;
}
