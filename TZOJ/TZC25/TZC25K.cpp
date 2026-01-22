#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

struct node {
	int ed;
	ll val;
};

vector< node > sts[1445];
ll dp[1445];
int n;

int main( )
{
	scanf("%d", &n);	
	
	for( int i = 1; i <= n; ++ i )
	{
		int h1, m1, h2, m2; ll val;
		scanf("%d:%d-%d:%d %lld", &h1, &m1, &h2, &m2, &val);
		int t1 = h1 * 60 + m1;
		int t2 = h2 * 60 + m2;
		sts[t1].push_back({ t2, val });
	}
	
	for( int i = 0; i < 1440; ++ i )
	{
		for( int j = 0; j < i; ++ j )
		{
			if( sts[j].empty( ) ) dp[i] = max( dp[i], dp[j] );
			else
			{
				for( auto [ed, val] : sts[j] )
				{
					if( ed <= i ) dp[i] = max( dp[i], dp[j] + val );
				}
			}
		}
	}
	cout << dp[1439] << '\n';
	
	return 0;
}
