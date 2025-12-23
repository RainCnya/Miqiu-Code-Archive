#include<bits/stdc++.h>
using namespace std;

const int N = 26 + 5;
const long long inf = 1e18;

long long dist[N][N];

string s1, s2;
int n;

void floyd( )
{
	for( int k = 0; k < 26; ++ k )
	{
		for( int i = 0; i < 26; ++ i )
		{
			for( int j = 0; j < 26; ++ j )
			{
				dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
			}
		}
	}
}

int main( )
{
	for( int i = 0 ; i < 26; ++ i )
	{
		for( int j = 0; j < 26; ++ j )
		{
			if( i == j ) dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}
	cin >> s1 >> s2 >> n;
	for( int i = 1; i <= n; ++ i )
	{
		char a, b;
		long long w;
		cin >> a >> b >> w;
		int u = a - 'a', v = b - 'a';
		dist[u][v] = min( dist[u][v], w );
	}
	floyd( );
	long long ans = 0;
	string res = "";
	int len1 = s1.length( );
	int len2 = s2.length( );
	if( len1 != len2 )
	{
		cout << -1 << endl;
		return 0;
	}
	for( int i = 0; i < len1; ++ i )
	{
		int u = s1[i] - 'a', v = s2[i] - 'a';
		long long minCost = inf;
		int minIdx = -1;
		if( u == v )	
		{
			res += s1[i];
			continue;
		}
		for( int j = 0; j < 26; ++ j )
		{
			long long cost = dist[u][j] + dist[v][j];
			if( cost < minCost )
			{
				minCost = cost;
				minIdx = j;
			}
		}
		if( minIdx == -1 || minCost >= inf )	
		{
			cout << -1 << endl;
			return 0;
		}
		ans += minCost;
		res += (minIdx + 'a');
	}
	cout << ans << endl;
	cout << res << endl;
	return 0;
}