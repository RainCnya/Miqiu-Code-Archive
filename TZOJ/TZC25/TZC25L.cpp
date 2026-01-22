#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxsum = 1000005;
const int maxn = 1005;

void solve( )
{
    int n, k;
	cin >> n >> k;

    if( k == 2 )
    {
        if( n < 5 ) cout << -1 << '\n';
        else
        {
            cout << n << '\n';
            
			vector< int > res;
            for( int i = 2; i <= n; i += 2 ) if( i != 4 ) res.push_back( i );
            res.push_back( 4 );
            res.push_back( 5 );
            for( int i = 1; i <= n; i += 2 ) if( i != 5 ) res.push_back( i );

            for( int i = 0; i < n; ++ i )
            {
				cout << res[ i ];
				if( i != n - 1 ) cout << " ";
            }
            cout << '\n';
        }
    }
    else
    {
        cout << n << "\n";
        for( int i = 1; i <= n; ++ i )
        {
			cout << i;
			if( i != n ) cout << " ";
        }
        cout << "\n";
    }
}

int main( )
{
	ios::sync_with_stdio( false );
	cin.tie( nullptr ); cout.tie( nullptr );

    int t = 1;
    cin >> t;
    while( t -- )
    {
        solve( );
    }
    return 0;
}