#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2000 + 50;
const ll inf = 1e18;

ll dp[maxn][maxn];
ll a[maxn];
int n, k;

ll dist( int x, int y )
{
	return ( a[x] - a[y] ) * ( a[x] - a[y] );
}

int main( )
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while( cin >> n >> k )
	{
		for( int i = 1; i <= n; ++ i )
		{
			cin >> a[i];
		}
		
		sort( a + 1, a + n + 1 );
		
		memset( dp, 0x3f, sizeof( dp ) );
		
		for( int i = 0; i <= n; ++ i )
		{
			dp[i][0] = 0;
		}
		
		for( int i = 2; i <= n; ++ i )
		{
			for( int j = 1; j * 2 <= i; ++ j )
			{
				int cost = dist( i, i-1 );
				dp[i][j] = min( dp[i-1][j], dp[i-2][j-1] + cost );
			}
		}
		
		cout << dp[n][k] << '\n';
	}
	
	return 0;
}
