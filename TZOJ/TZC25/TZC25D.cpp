#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

ll s1[maxn], s2[maxn], s3[maxn];

ll calc( ll a, ll b, ll c )
{
	return abs( a - b ) + abs( b - c ) + abs( c - a );
}

int main( )
{	
	ios::sync_with_stdio( 0 );
	cin.tie( 0 ), cout.tie( 0 );
	
	int t;
	cin >> t;
	
	while( t -- )
	{
		int x, y, z;
		cin >> x >> y >> z;
		
		for( int i = 1; i <= x; ++ i ) cin >> s1[i];
		for( int i = 1; i <= y; ++ i ) cin >> s2[i];
		for( int i = 1; i <= z; ++ i ) cin >> s3[i];
		
		sort( s1 + 1, s1 + x + 1 );
		sort( s2 + 1, s2 + y + 1 );
		sort( s3 + 1, s3 + z + 1 );
		
		long long ans = 1e18;
		
		int i = 1, j = 1, k = 1;
		while( i <= x && j <= y && k <= z )
		{
			int min_num = 1e9, min_pos = -1;
			if( s1[i] < min_num )
			{
				min_num = s1[i];
				min_pos = 1;
			}
			if( s2[j] < min_num )
			{
				min_num = s2[j];
				min_pos = 2;
			}
			if( s3[k] < min_num )
			{
				min_num = s3[k];
				min_pos = 3;
			}
			ans = min( ans, calc( s1[i], s2[j], s3[k] ) );
			if( min_pos == 1 ) i++;
			else if( min_pos == 2 ) j ++;
			else k ++;
		}
		// cout << i << " " << j << " " << k << " " << x << " " << y << " " << z << " " << '\n';  
		cout << ans << '\n';
	}
	return 0;
}
