#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;
char E[maxn], O[maxn];

struct Node {
    int cnt;
    char c;
    bool operator < ( const Node& oth ) const { return cnt < oth.cnt; }
} a[3];

ll r, g, b;

void solve( )
{
    cin >> a[0].cnt >> a[1].cnt >> a[2].cnt;
    a[0].c = 'R', a[1].c = 'G', a[2].c = 'B';
    sort( a, a + 3 );

    int x = a[0].cnt; char cx = a[0].c;
    int y = a[1].cnt; char cy = a[1].c;
    int z = a[2].cnt; char cz = a[2].c;

    int len = min( x + y + z, 2 * ( x + y ) + 1 );
    int A = ( len + 1 ) / 2;
    int B = len / 2;
    int zz = len - x - y;

    for( int i = A - zz; i < A; ++ i ) E[i] = cz;

    int pe = 0, po = B - 1;

    for( int i = 1; i <= x; ++ i )
    {
        if( pe < A - zz ) E[pe++] = cx;
        else O[po--] = cx;
    }

    for( int i = 1; i <= y; ++ i )
    {
        if( pe < A - zz ) E[pe++] = cy;
        else O[po--] = cy;
    }

    for( int i = 0; i < len; ++ i )
    {
        if( i % 2 == 0 ) cout << E[i / 2];
        else cout << O[i / 2];
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}
