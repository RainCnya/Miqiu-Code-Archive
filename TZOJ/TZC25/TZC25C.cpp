#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main( )
{
	ll a, b;
	cin >> a >> b;
	
	ll A = (a & b) ^ (a | b);
	ll B = (a ^ b);
	
	if( A > B ) cout << 1 << '\n';
	else if( A == B ) cout << 0 << '\n';
	else cout << -1 << '\n';
	return 0;
}
