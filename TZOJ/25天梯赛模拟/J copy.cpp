#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set< int > s;
vector< int > Y0, Y1, Y2;
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x, y;
        cin >> x >> y;
        if( y == 0 ) Y0.push_back( x );
        else if( y == 1 ) Y1.push_back( x );
        else if( y == 2 ) Y2.push_back( x ), s.insert( x );
    }

    sort( Y0.begin( ), Y0.end( ) );
    Y0.erase( unique( Y0.begin( ), Y0.end( ) ), Y0.end( ) );
    sort( Y1.begin( ), Y1.end( ) );
    Y1.erase( unique( Y1.begin( ), Y1.end( ) ), Y1.end( ) );
    sort( Y2.begin( ), Y2.end( ) );
    Y2.erase( unique( Y2.begin( ), Y2.end( ) ), Y2.end( ) );

    bool found = 0;
    for( int X1 : Y1 )
    {
        for( int X0 : Y0 )
        {
            int X2 = X1 + X1 - X0;
            if( s.find( X2 ) != s.end( ) )
            {
                found = 1;
                cout << "[" << X0 << ", " << 0 << "]" << ' ';
                cout << "[" << X1 << ", " << 1 << "]" << ' ';
                cout << "[" << X2 << ", " << 2 << "]" << '\n';
            }
        }
    }
    if( !found ) cout << "-1" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}