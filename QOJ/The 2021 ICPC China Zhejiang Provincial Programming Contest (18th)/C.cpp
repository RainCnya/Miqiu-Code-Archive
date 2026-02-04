#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

struct Point {
    int x, y, z;
};

int dist( Point a, Point b ) {
    return ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) + ( a.z - b.z ) * ( a.z - b.z );
}

bool solve( )
{
    vector<Point> p(8);
    for( int i = 0; i < 8; ++ i )
    {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    vector<int> dists;
    for( int i = 0; i < 8; ++ i )
    {
        for( int j = i + 1; j < 8; ++ j )
        {
            int d = dist( p[i], p[j] );
            if( d == 0 ) return 0;
            dists.push_back( d );
        }
    }

    sort( dists.begin( ), dists.end( ) );
    int d = dists[0];

    for( int i = 0; i < 28; ++ i )
    {
        if( i < 12 ) {
            if( dists[i] != d ) return 0;
        } else if( i < 24 ) {
            if( dists[i] != 2 * d ) return 0;
        } else {
            if( dists[i] != 3 * d ) return 0;
        }
    }

    return 1;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        if( solve( ) ) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}