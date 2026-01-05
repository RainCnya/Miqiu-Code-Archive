#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, t;

__int128__ calc( __int128__ x, __int128__ y )
{
	return ( ( x - y ) + ( x ^ y ) ) >> 1;
}

int main( )
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while( t -- )
	{
		ll _a1, _b1, _A, _B, _C;	
		
		cin >> n >> _a1 >> _b1;	
		cin >> _A >> _B >> _C;
		
		__int128__ a1 = _a1, b1 = _b1;
		__int128__ A = _A, B = _B, C = _C;
		
		__int128 c1 = calc( a1, b1 );
		
		for( int i = 2; i <= n; ++ i )
		{
			__int128__ a2 = ( ( ( a1 * b1 ) % B * c1 ) % B + A ) % B;
			__int128__ b2 = ( ( a2 * c1 ) % C + B ) % C;
			__int128__ c2 = calc( a2, b2 );
			a1 = a2, b1 = b2, c1 = c2;
			 //cout << i << " " << (ll)c2 << '\n';
		}
		cout << (long long)c1 << '\n';
	}
	
	return 0;
}
