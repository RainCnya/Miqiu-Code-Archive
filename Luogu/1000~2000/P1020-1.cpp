#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int a[maxn];
int n;

int main()
{	
    int t;
    while( cin >> t ) a[++ n] = t;

	vector< int > d1;
    for( int i = 1; i <= n; ++ i )
    {
        auto it = upper_bound( d1.begin( ), d1.end( ), a[i], greater< int >( ) );
        if( it == d1.end( ) ) d1.push_back( a[i] );
        else *it = a[i];
    }
    cout << d1.size( ) << '\n';

    vector< int > d2;
    for( int i = 1; i <= n; ++ i )
    {
        auto it = lower_bound( d2.begin( ), d2.end( ), a[i] );
        if( it == d2.end( ) ) d2.push_back( a[i] );
        else *it = a[i];
    }
    cout << d2.size( ) << '\n';

    return 0;
}