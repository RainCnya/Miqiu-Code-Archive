#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;

vector< int > divs[ maxn ];
int bucket[ maxn ];
int p[ maxn ];
int cnt[ maxn ];

void init( )
{
	for( int i = 1; i < maxn; ++ i )
	{
		for( int j = i; j < maxn; j += i )
		{
			cnt[ j ] ++;
		}
	}
	for( int i = 1; i < maxn; ++ i )
	{
		divs[ i ].reserve( cnt[ i ] );
	}
	for( int i = 1; i < maxn; ++ i )
	{
		for( int j = i; j < maxn; j += i )
		{
			divs[ j ].push_back( i );
		}
	}
}

void solve( )
{
	int n, k;
	cin >> n >> k;
	
	for( int i = 1; i <= n; ++ i )	cin >> p[ i ];

	if( n == k )
	{
		cout << -1 << '\n';
		return ;
	}

	int ans = 1;
	for( int i = 1; i <= n; ++ i )
	{
		for( int &d : divs[ p[ i ] ] )
		{
			bucket[ d ] ++;
			if( bucket[ d ] >= n - k )
			{
				ans = max( ans, d );
			}
		}
	}

	cout << ans << '\n';

	for( int i = 1; i <= n; ++ i )
	{
		for( int &d : divs[ p[ i ] ] )
		{
			bucket[ d ] --;
		}
	}
}

int main( )
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init( );
	
	int _t = 1;
	cin >> _t;
	while( _t -- )
	{
		solve( );
	}
	return 0;
}
