#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;

string s;
int n, x, y;

void solve( )
{
    cin >> n >> x >> y;
    cin >> s;
    int cnt4 = 0, cnt8 = 0;
    for( char c : s )
    {
        if( c == '4' ) cnt4 ++;
        else cnt8 ++;
    }

    int diff = cnt4 + cnt8;
    if( -diff <= x && x <= diff && -diff <= y && y <= diff )
    {
        int d1 = cnt4 + cnt8 * 2;
        int d2 = abs( x ) + abs( y );
        if( d1 >= d2 ) cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }

}

int main( )
{	
    int t;
    cin >> t;
    while( t -- )
    {
        solve( );
    }
    return 0;
}