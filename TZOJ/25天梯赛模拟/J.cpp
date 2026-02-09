#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int offset = 1e6;

bitset< (offset << 1) > exist;
vector< int > Y0, Y1;
int n;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    int maxy2 = -offset, miny0 = offset;

    for( int i = 1; i <= n; ++ i )
    {
        int x, y;
        cin >> x >> y;
        if( y == 0 ) Y0.push_back( x );
        else if( y == 1 ) Y1.push_back( x );
        else if( y == 2 ) exist.set( x + offset ), maxy2 = max( maxy2, x ), miny0 = min( miny0, x );
    }

    sort( Y0.begin( ), Y0.end( ) );
    Y0.erase( unique( Y0.begin( ), Y0.end( ) ), Y0.end( ) );
    sort( Y1.begin( ), Y1.end( ) );
    Y1.erase( unique( Y1.begin( ), Y1.end( ) ), Y1.end( ) );

    bool found = 0;
    for( int X1 : Y1 )
    {
        for( int X0 : Y0 )
        {
            int X2 = X1 + X1 - X0;
            if( X2 < miny0 || X2 > maxy2 ) continue;

            if( exist.test( X2 + offset ) )
            {
                found = 1;
                cout << "[" << X0 << ", 0] " << "[" << X1 << ", 1] " << "[" << X2 << ", 2]" << '\n'; 
            }
        }
    }
    if( !found ) cout << "-1" << '\n';
    return 0;
}