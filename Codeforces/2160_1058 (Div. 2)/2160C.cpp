#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	if( s != t ) {
		return false;
	}
	int len = s.length( );
	bool flag1 = len % 2 == 1;
	bool flag2 = s[len / 2] == '1';
	if( flag1 && flag2 ) {
		return false;
	} 
	return true;
}

int main( )
{
	int t;	cin >> t;
	while( t -- )
	{
		int n;	cin >> n;
		if( n == 0 ) 
		{
			cout << "YES" << endl;
			continue;
		}
		
		string s = "";
		while( n ) {
			s += (n % 2) + '0';
			n /= 2;
		}
		reverse( s.begin( ), s.end( ) );

		bool found = false;
		if( check( s ) )
			found = true;

		if( !found ) 
		{
			for( int i = 0; i <= 30; ++ i )
			{
				s = "0" + s;
				if( check(s) ) {		
					found = true;
					break;
				}
			}
		}
		if( found ) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}