#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int calc( string s )
{
	//cout << s << '\n';
	if( s == ".____" ) return 1;
	else if( s == "..___" ) return 2;
	else if( s == "...__" ) return 3;
	else if( s == "...._" ) return 4;
	else if( s == "....." ) return 5;
	else if( s == "_...." ) return 6;
	else if( s == "__..." ) return 7;
	else if( s == "___.." ) return 8;
	else if( s == "____." ) return 9;
	else return 0;
}

int main( )
{
	int t;
	cin >> t;
	while( t -- )
	{
		int n;
		cin >> n;
		getchar( );
		string s;
		getline( cin, s );
		int cnt = n / 5;
		
		for( int k = 0; k < cnt; ++ k )
		{
			string tmp = "";
			for( int i = 0; i < 5; ++ i )
			{
				tmp += s[ k * 5 + i ];
			}
			cout << calc( tmp );
		}
		
	}
	return 0;
}
