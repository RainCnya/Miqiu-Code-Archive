#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

void solve( )
{
    queue< int > A, B;
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x; cin >> x;
        if( x & 1 ) A.push( x );
        else B.push( x );
    }

    vector< int > ans;
    while( !A.empty( ) || !B.empty( ) )
    {
        if( !A.empty( ) )
        {
            ans.push_back( A.front( ) );
            A.pop( );
        }
        if( !A.empty( ) )
        {
            ans.push_back( A.front( ) );
            A.pop( );
        }
        if( !B.empty( ) )
        {
            ans.push_back( B.front( ) );
            B.pop( );
        }
    }

    bool first = 1;
    for( int x : ans ) 
    {
        if( first ) first = 0;
        else cout << " ";
        cout << x;
    }

}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}