#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

int hh[maxn];

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    int l, h, r;
    int minl = maxn, maxr = 0;

    while( cin >> l >> h >> r )
    {
        for( int i = l; i < r; ++ i )
        {
            hh[i] = max( hh[i], h );
        }
        minl = min( minl, l );
        maxr = max( maxr, r );
    }

    int cur = 0;
    for( int i = minl; i <= maxr; ++ i )
    {
        if( hh[i] != cur )
        {
            cout << i << " " << hh[i] << ' ';
            cur = hh[i];
        }
    }

    return 0;
}